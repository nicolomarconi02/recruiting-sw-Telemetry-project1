#include "image.h"

using namespace std;

Image::Image(const char* path){
    filepath = path;
    cout << filepath;
}

// Simple helper function to load an image into a OpenGL texture with common settings
bool Image::LoadTextureFromFile()
{
    // Load from file
    unsigned char* image_data = stbi_load(filepath, &image_width, &image_height, NULL, 4);
    if (image_data == NULL)
        return false;

    // Create a OpenGL texture identifier
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

    // Upload pixels into texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);
    setSize();
    return true;
}

void Image::setSize(){
    float prefSize = 600;
    float ratio = (float) image_height/image_width;
    // if((image_height < prefSize) || (image_width < prefSize)){
        if(max(image_height,image_width) - min(image_height, image_width) <= 50){
            //immagine "quadrata"
            image_height = (int) prefSize;
            image_width = (int) prefSize;
        }
        else{
            image_height = (int) prefSize * ratio;
            image_width = (int) prefSize;
        }
    // }
    // else if((image_height > prefSize * 3/2) || (image_width > prefSize * 3/2)){
    //     if(max(image_height,image_width) - min(image_height, image_width) <= 50){
    //         //immagine "quadrata"
    //         image_height = (int) prefSize;
    //         image_width = (int) prefSize;
    //     }
    //     else{
    //         image_height = (int) prefSize * ratio;
    //         image_width = (int) prefSize;
    //     }
    // }
}