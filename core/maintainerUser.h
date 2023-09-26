#ifndef MAINTAINER_H
#define MAINTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include "basicUser.h"

using namespace std;

class MaintainerUser : public BasicUser{
    public:
        MaintainerUser(const char* us, const char* pass, int perm) : BasicUser(us, pass, perm){}
        void prova();
        bool checkLogin(vector<MaintainerUser>);
        void setupProfileWindow() override;
};

#endif