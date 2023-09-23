#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class MotorData : public Data{
    public:
        float motorAge;
        float inverterAge;
        float motorTemperature;
        float inverterTemperature;

        MotorData(){
            initializeData();
        }

        void initializeData();
};