#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "error.h"

using namespace std;

// Definition of the Data class
class Data {
public:
    // Public member variable of the Error class
    Error error;

    // Constructor for the Data class
    Data() {}

    // Function declaration: generateRandomData
    // This function generates random float data within a specified range.
    // Parameters:
    //   - min: The minimum value of the range (inclusive).
    //   - max: The maximum value of the range (exclusive).
    float generateRandomData(int min, int max);
};
#endif 

