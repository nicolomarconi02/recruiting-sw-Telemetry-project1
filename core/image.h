#ifndef IMAGE_H
#define IMAGE_H

#include <GL/glew.h>
#include <string>
#include <iostream>
#include "stb_image.h"

using namespace std;

class Image {
public:
    int image_width = 0;       // Width of the image
    int image_height = 0;      // Height of the image
    GLuint image_texture = 0;  // OpenGL texture identifier
    string filepath;           // Filepath to the image

    // Constructor with a default filepath
    Image() {
        filepath = "../data/Hockenheim2012.jpg";
    }

    // Constructor with a custom filepath
    Image(string path) {
        filepath = "../data/" + path;
    }

    // Function to load an image from the file and create an OpenGL texture
    bool LoadTextureFromFile();

    // Function to set the size of the image for rendering
    void setSize();
};

#endif