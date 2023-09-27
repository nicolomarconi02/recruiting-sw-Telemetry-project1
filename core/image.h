#ifndef IMAGE_H
#define IMAGE_H

#include <GL/glew.h>
#include <string.h>
#include <iostream>
#include "stb_image.h"

using namespace std;

class Image{
    public: 
        int image_width = 0;
        int image_height = 0;
        GLuint image_texture = 0;
        char filepath[64];

        Image(){
            // filepath = "Hockenheim2012.jpg";
            strcpy(filepath, "Hockenheim2012.jpg");
        }

        Image(const char* path){
            strcpy(filepath, path);
            // filepath = path;
            cout << filepath;
        }
        bool LoadTextureFromFile();  
        void setSize();
};

#endif