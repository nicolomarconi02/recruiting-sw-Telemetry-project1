#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <vector>

using namespace std;

class Error{
    public:
        vector<string> electronicErrorList;
        vector<string> tyreErrorList;
        vector<string> motorErrorList;
};

#endif