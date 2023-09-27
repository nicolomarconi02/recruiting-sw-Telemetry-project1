#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <vector>

using namespace std;

class Error{
    public:
        // Public member variables to store error lists for different components
        vector<string> electronicErrorList; // Stores electronic-related errors
        vector<string> tyreErrorList;       // Stores tyre-related errors
        vector<string> motorErrorList;      // Stores motor-related errors
};

#endif