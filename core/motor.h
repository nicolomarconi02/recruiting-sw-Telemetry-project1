#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class MotorData : public Data { // Inheriting from the base class 'Data'
public:
    // Constructor that initializes data and sets errors
    MotorData() {
        initializeData(); // Initialize motor data
        setError();      // Set errors based on data
    }

    // Function declarations for initializing data and setting errors
    void initializeData(); // Initialize motor data
    void setError();      // Set errors based on motor data

    // Setter functions for various motor properties
    void setMotorAge(float);
    void setInverterAge(float);
    void setMotorTemperature(float);
    void setInverterTemperature(float);
    void setMotorState(float);
    void setInverterState(float);

    // Getter functions for various motor properties
    float getMotorAge();
    float getInverterAge();
    float getMotorTemperature();
    float getInverterTemperature();
    float getMotorState();
    float getInverterState();

private:
    // Private member variables to store motor-related data
    float motorAge;
    float inverterAge;
    float motorTemperature;
    float inverterTemperature;
    float motorState;
    float inverterState;
};