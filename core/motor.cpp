#include "motor.h"

using namespace std;

// Initialize the data for the MotorData class
void MotorData::initializeData() {
    srand(time(NULL));  // Seed the random number generator with the current time

    // Set various motor-related properties with random values
    setMotorAge(generateRandomData(0, 500));
    setInverterAge(generateRandomData(0, 500));
    setMotorTemperature(generateRandomData(60, 80));
    setInverterTemperature(generateRandomData(50, 70));
    setMotorState(generateRandomData(0, 1));
    setInverterState(generateRandomData(0, 1));
}

// Set error conditions based on motor and inverter properties
void MotorData::setError() {
    if (motorTemperature > 70) {
        error.motorErrorList.push_back("CRITICAL MOTOR TEMPERATURE");
    } else if (motorTemperature > 65 && motorTemperature <= 70) {
        error.motorErrorList.push_back("WARNING MOTOR TEMPERATURE");
    }
    if (inverterTemperature > 60) {
        error.motorErrorList.push_back("CRITICAL INVERTER TEMPERATURE");
    } else if (inverterTemperature > 55 && inverterTemperature <= 60) {
        error.motorErrorList.push_back("WARNING INVERTER TEMPERATURE");
    }
    if (motorState < 0.1f) {
        error.motorErrorList.push_back("CRITICAL MOTOR STATE");
    } else if (motorState >= 0.1f && motorState <= 0.15f) {
        error.motorErrorList.push_back("WARNING MOTOR STATE");
    }
    if (inverterState < 0.1f) {
        error.motorErrorList.push_back("CRITICAL INVERTER STATE");
    } else if (inverterState >= 0.1f && inverterState <= 0.15f) {
        error.motorErrorList.push_back("WARNING INVERTER STATE");
    }
}

// Set the age of the motor
void MotorData::setMotorAge(float v) {
    motorAge = v;
}

// Set the age of the inverter
void MotorData::setInverterAge(float v) {
    inverterAge = v;
}

// Set the temperature of the motor
void MotorData::setMotorTemperature(float v) {
    motorTemperature = v;
}

// Set the temperature of the inverter
void MotorData::setInverterTemperature(float v) {
    inverterTemperature = v;
}

// Set the state of the motor
void MotorData::setMotorState(float v) {
    motorState = v;
}

// Set the state of the inverter
void MotorData::setInverterState(float v) {
    inverterState = v;
}

// Get the age of the motor
float MotorData::getMotorAge() {
    return motorAge;
}

// Get the age of the inverter
float MotorData::getInverterAge() {
    return inverterAge;
}

// Get the temperature of the motor
float MotorData::getMotorTemperature() {
    return motorTemperature;
}

// Get the temperature of the inverter
float MotorData::getInverterTemperature() {
    return inverterTemperature;
}

// Get the state of the motor
float MotorData::getMotorState() {
    return motorState;
}

// Get the state of the inverter
float MotorData::getInverterState() {
    return inverterState;
}
