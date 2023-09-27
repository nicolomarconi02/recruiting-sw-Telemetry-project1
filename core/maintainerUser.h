#ifndef MAINTAINER_H
#define MAINTAINER_H

#include <iostream>
#include <vector>
#include <string>
#include "basicUser.h"

using namespace std;

#define CONVERTER 255.0f
#define GRAY_LIGHT ImVec4(155/CONVERTER, 155/CONVERTER, 155/CONVERTER, 1.0f)
#define GRAY_MID_LIGHT ImVec4(140/CONVERTER, 140/CONVERTER, 140/CONVERTER, 1.0f)
#define GRAY_MID ImVec4(120/CONVERTER, 120/CONVERTER, 120/CONVERTER, 1.0f)
#define GRAY_MID_DARK ImVec4(102/CONVERTER, 102/CONVERTER, 102/CONVERTER, 1.0f)
#define GRAY_DARK ImVec4(80/CONVERTER, 80/CONVERTER, 80/CONVERTER, 1.0f)
#define GRAY_DARK_DEEP ImVec4(55/CONVERTER, 55/CONVERTER, 55/CONVERTER, 1.0f)
#define BLACK_LIGHT ImVec4(36/CONVERTER, 36/CONVERTER, 36/CONVERTER, 1.0f)
#define BLACK ImVec4(0/CONVERTER, 0/CONVERTER, 0/CONVERTER, 1.0f)

class MaintainerUser : public BasicUser{
    public:
        MaintainerUser(string us, string pass, int perm) : BasicUser(us, pass, perm){}

        void setupProfileWindow() override;
        void setupStyle() override;
};

#endif