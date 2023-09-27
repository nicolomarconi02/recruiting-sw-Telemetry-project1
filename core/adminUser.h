#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <vector>
#include "maintainerUser.h"

using namespace std;

class AdminUser : public MaintainerUser{
    public:
        AdminUser(string us, string pass, int perm) : MaintainerUser(us, pass, perm){}
        // AdminUser(const char* us, const char* pass, int perm) : MaintainerUser(us, pass, perm){}
        void setupProfileWindow() override;  
};


#endif