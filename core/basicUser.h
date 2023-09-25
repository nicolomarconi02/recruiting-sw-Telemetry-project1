#ifndef BASICUSR_H
#define BASICUSR_H

#include <iostream>
#include <vector>
#include <string.h>

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

        ~BasicUser(){
            delete this;
        }

        bool checkLogin();
};

#endif 
