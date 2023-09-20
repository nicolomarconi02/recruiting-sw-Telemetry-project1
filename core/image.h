#include <GL/glew.h>
#include <string>
#include <iostream>
#include "stb_image.h"

using namespace std;

class Image{
    public: 
        int image_width = 0;
        int image_height = 0;
        GLuint image_texture = 0;
        const char* filepath;

        Image(const char* path);
        bool LoadTextureFromFile();  
};