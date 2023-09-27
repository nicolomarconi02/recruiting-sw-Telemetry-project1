#ifndef BASICUSR_H
#define BASICUSR_H

#include <iostream>
#include <vector>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include <string>
#include <memory>

#define CONVERTER 255.0f
#define YELLOW_LIGHT ImVec4(212/CONVERTER, 230/CONVERTER, 30/CONVERTER, 1.0f)
#define YELLOW_MID_LIGHT ImVec4(188/CONVERTER, 206/CONVERTER, 8/CONVERTER, 1.0f)
#define YELLOW_MID ImVec4(222/CONVERTER, 211/CONVERTER, 21/CONVERTER, 1.0f)
#define YELLOW_MID_DARK ImVec4(255/CONVERTER, 173/CONVERTER, 51/CONVERTER, 1.0f)
#define YELLOW_DARK ImVec4(255/CONVERTER, 153/CONVERTER, 0/CONVERTER, 1.0f)
#define ORANGE_LIGHT ImVec4(191/CONVERTER, 149/CONVERTER, 0/CONVERTER, 1.0f)
#define ORANGE_MID ImVec4(147/CONVERTER, 115/CONVERTER, 0/CONVERTER, 1.0f)
#define ORANGE_DARK ImVec4(85/CONVERTER, 67/CONVERTER, 0/CONVERTER, 1.0f)

using namespace std;

class BasicUser{
    public:
        int permission;
        string username;
        string password;

        BasicUser(string us, string pass, int perm){
            permission = perm;
            username = us;
            password = pass;
        }

        virtual void setupProfileWindow();
        virtual void setupStyle();
        void removeStyle();
    private:
        
};

#endif 
