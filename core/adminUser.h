#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "maintainerUser.h"

using namespace std;

// Define a class named AdminUser that inherits from MaintainerUser.
class AdminUser : public MaintainerUser {
public:
    // Constructor for the AdminUser class.
    // It takes three parameters: a username (us), a password (pass), and permission level (perm).
    AdminUser(string us, string pass, int perm) : MaintainerUser(us, pass, perm) {}
    
    // Override the setupProfileWindow function, which is declared in the MaintainerUser class.
    // This function is specific to AdminUser and can provide custom behavior.
    void setupProfileWindow() override;
};

#endif