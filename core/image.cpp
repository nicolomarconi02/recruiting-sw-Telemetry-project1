#include "image.h"

using namespace std;

// Function to load an image into an OpenGL texture with common settings
bool Image::LoadTextureFromFile(){
    // Load image data from the file using the STB image library (stb_image)
    unsigned char* image_data = stbi_load(filepath.c_str(), &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create an OpenGL texture identifier
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload image pixels into the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);

    // Free the image data as it's no longer needed
    stbi_image_free(image_data);

    // Set the size of the image for rendering
    setSize();

    return true;
}

// Helper function to set the size of the image for rendering
void Image::setSize(){
    // Preferred size for displaying the image
    float prefSize = 600;

    // Calculate the aspect ratio of the image
    float ratio = (float)image_height / image_width;

    // Check if the difference between image width and height is small (square or nearly square image)
    if (max(image_height, image_width) - min(image_height, image_width) <= 50){
        // Set both width and height to the preferred size (making it square)
        image_height = (int)prefSize;
        image_width = (int)prefSize;
    }
    else{
        // Set the height based on the aspect ratio while keeping the width as the preferred size
        image_height = (int)(prefSize * ratio);
        image_width = (int)prefSize;
    }
}