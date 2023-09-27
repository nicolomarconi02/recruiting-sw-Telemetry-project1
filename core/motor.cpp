#include "motor.h"

using namespace std;

void MotorData::initializeData(){
    srand(time(NULL));
    setMotorAge(generateRandomData(0, 500));
    setInverterAge(generateRandomData(0, 500));
    setMotorTemperature(generateRandomData(60, 80));
    setInverterTemperature(generateRandomData(50, 70));
    setMotorState(generateRandomData(0, 1));
    setInverterState(generateRandomData(0, 1));
}

void MotorData::setError(){
    if(motorTemperature > 70){
        error.motorErrorList.push_back("CRITICAL MOTOR TEMPERATURE");
    }
    else if(motorTemperature > 65 && motorTemperature <= 70){
        error.motorErrorList.push_back("WARNING MOTOR TEMPERATURE");
    }
    if(inverterTemperature > 60){
        error.motorErrorList.push_back("CRITICAL INVERTER TEMPERATURE");
    }
    else if(inverterTemperature > 55 && inverterTemperature <= 60){
        error.motorErrorList.push_back("WARNING INVERTER TEMPERATURE");
    }
    if(motorState < 0.1f){
        error.motorErrorList.push_back("CRITICAL MOTOR STATE");
    }
    else if(motorState >= 0.1f && motorState <= 0.15f){
        error.motorErrorList.push_back("WARNING MOTOR STATE");
    }
    if(inverterState < 0.1f){
        error.motorErrorList.push_back("CRITICAL INVERTER STATE");
    }
    else if(inverterState >= 0.1f && inverterState <= 0.15f){
        error.motorErrorList.push_back("WARNING INVERTER STATE");
    }

}

void MotorData::setMotorAge(float v){
    motorAge = v;
}
void MotorData::setInverterAge(float v){
    inverterAge = v;
}
void MotorData::setMotorTemperature(float v){
    motorTemperature = v;
}
void MotorData::setInverterTemperature(float v){
    inverterTemperature = v;
}
void MotorData::setMotorState(float v){
    motorState = v;
}
void MotorData::setInverterState(float v){
    inverterState = v;
}

float MotorData::getMotorAge(){
    return motorAge;
}
float MotorData::getInverterAge(){
    return inverterAge;
}
float MotorData::getMotorTemperature(){
    return motorTemperature;
}
float MotorData::getInverterTemperature(){
    return inverterTemperature;
}
float MotorData::getMotorState(){
    return motorState;
}
float MotorData::getInverterState(){
    return inverterState;
}