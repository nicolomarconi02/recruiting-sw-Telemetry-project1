#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "error.h"

using namespace std;

class Data{
    public:
        Error error;
        Data(){}
        float generateRandomData(int, int);
};

#endif 

