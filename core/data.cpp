#include "data.h"

using namespace std;

// This function generates random float data within a specified range [min, max].
float Data::generateRandomData(int min, int max) {
    // Generate a random integer between min (inclusive) and max (exclusive).
    int randomInt = min + rand() % (max - min);

    // Generate a random float between 0 and 1, and add it to the random integer.
    // This creates a random float between [min, max) with some decimal precision.
    float randomFloat = ((float)rand()) / ((float)RAND_MAX);

    // Combine the random integer and random float to get the final random float value.
    float randomData = (float)randomInt + randomFloat;

    // Return the generated random data.
    return randomData;
}