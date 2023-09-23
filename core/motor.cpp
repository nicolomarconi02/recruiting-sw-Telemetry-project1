#include "motor.h"

using namespace std;

void MotorData::initializeData(){
    srand(time(NULL));
    motorAge = generateRandomData(0, 500);
    inverterAge = generateRandomData(0, 500);
    motorTemperature = generateRandomData(20, 80);
    inverterTemperature = generateRandomData(20, 70);
}