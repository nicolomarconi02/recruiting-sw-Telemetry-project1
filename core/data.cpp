#include "data.h"

using namespace std;

float Data::generateRandomData(int min, int max){
    return (float) (min + rand() % (max-min)) + (((float) rand())/((float)RAND_MAX));
}