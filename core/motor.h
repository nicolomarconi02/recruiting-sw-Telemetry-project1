#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class MotorData : public Data{
    public:

        MotorData(){
            initializeData();
            setError();
        }

        void initializeData();
        void setError();

        void setMotorAge(float);
        void setInverterAge(float);
        void setMotorTemperature(float);
        void setInverterTemperature(float);
        void setMotorState(float);
        void setInverterState(float);

        float getMotorAge();
        float getInverterAge();
        float getMotorTemperature();
        float getInverterTemperature();
        float getMotorState();
        float getInverterState();

    private:
        float motorAge;
        float inverterAge;
        float motorTemperature;
        float inverterTemperature;
        float motorState;
        float inverterState;
};