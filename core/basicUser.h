#ifndef BASICUSR_H
#define BASICUSR_H

#include <iostream>
#include <vector>
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_glfw.h"
#include "imgui/backends/imgui_impl_opengl2.h"
#include <GL/glew.h>
#include <string.h>
#include <memory>

using namespace std;

class BasicUser{
    public:
        int permission;
        char username[64];
        char password[64];
        BasicUser(const char* us, const char* pass, int perm){
            permission = perm;
            strncpy(username, us, sizeof(username) - 1);
            username[sizeof(username) - 1] = '\0'; // Ensure null-termination.
            
            strncpy(password, pass, sizeof(password) - 1);
            password[sizeof(password) - 1] = '\0'; // Ensure null-termination.

        }

        virtual void setupProfileWindow();
};

#endif 
