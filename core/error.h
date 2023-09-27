#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <vector>

using namespace std;

class Error{
    public:
        vector<const char*> electronicErrorList;
        vector<const char*> tyreErrorList;
        vector<const char*> motorErrorList;
};

#endif