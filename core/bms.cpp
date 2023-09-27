#include "bms.h"

void BMSData::initializeData(){
    srand(time(NULL));

    for(int i = 0; i < numCellHV; i++){
        float gen = generateRandomData(0, 4);
        bmsHVVoltage.push_back(gen);
        setBMSHVTotalVoltage(gen);
        gen = generateRandomData(20, 40);
        bmsHVTemperature.push_back(gen);
        setBMSHVTotalTemperature(gen);
    }
    for(int i = 0; i < numCellLV; i++){
        float gen = generateRandomData(0, 4);
        bmsLVVoltage.push_back(gen);
        setBMSLVTotalVoltage(gen);
        gen = generateRandomData(20, 50);
        bmsLVTemperature.push_back(gen);
        setBMSLVTotalTemperature(gen);
    }
    setBMSHVAGE(generateRandomData(0, 500));
    setBMSLVAGE(generateRandomData(0, 500));
    setBMSLVCURRENT(generateRandomData(0, 30));
    
    bmsHVTotalTemperature = (float) getBMSHVTotalTemperature() / getNumCellHV();
    bmsLVTotalTemperature = (float) getBMSLVTotalTemperature() / getNumCellLV();
}

void BMSData::setError(){
    if((bmsHVTotalVoltage * 100)/(numCellHV *4) < 15){
        error.electronicErrorList.push_back("CRITICAL BMS HV VOLTAGE");
    }
    else if((bmsHVTotalVoltage * 100)/(numCellHV *4) >= 15 && bmsHVTotalVoltage/numCellHV < 30){
        error.electronicErrorList.push_back("WARNING BMS HV VOLTAGE");
    }
    if((bmsLVTotalVoltage * 100)/(numCellLV *4) < 15){
        error.electronicErrorList.push_back("CRITICAL BMS LV VOLTAGE");
    }
    else if((bmsLVTotalVoltage * 100)/(numCellLV *4) >= 15 && bmsLVTotalVoltage/numCellLV < 30){
        error.electronicErrorList.push_back("WARNING BMS LV VOLTAGE");
    }
    if(bmsHVTotalTemperature > 35){
        error.electronicErrorList.push_back("CRITICAL BMS HV TEMPERATURE");
    }
    else if(bmsHVTotalTemperature > 30 && bmsHVTotalTemperature <= 35){
        error.electronicErrorList.push_back("WARNING BMS HV TEMPERATURE");
    }
    if(bmsLVTotalTemperature > 45){
        error.electronicErrorList.push_back("CRITICAL BMS LV TEMPERATURE");
    }
    else if(bmsLVTotalTemperature > 40 && bmsLVTotalTemperature <= 45){
        error.electronicErrorList.push_back("WARNING BMS LV TEMPERATURE");
    }
}

void BMSData::setNumCellHV(int v){
    numCellHV = v;
}
void BMSData::setNumCellLV(int v){
    numCellLV = v;
}
void BMSData::setBMSHVAGE(float v){
    bmsHVAge = v;
}
void BMSData::setBMSLVAGE(float v){
    bmsLVAge = v;
}
void BMSData::setBMSLVCURRENT(float v){
    bmsLVCurrent = v;
}
void BMSData::setBMSHVTotalTemperature(float v){
    bmsHVTotalTemperature += v;
}
void BMSData::setBMSLVTotalTemperature(float v){
    bmsLVTotalTemperature += v;
}
void BMSData::setBMSHVTotalVoltage(float v){
    bmsHVTotalVoltage += v;
}
void BMSData::setBMSLVTotalVoltage(float v){
    bmsLVTotalVoltage += v;
}

int BMSData::getNumCellHV(){
    return numCellHV;
}
int BMSData::getNumCellLV(){
    return numCellLV;
}
float BMSData::getBMSHVAGE(){
    return bmsHVAge;
}
float BMSData::getBMSLVAGE(){
    return bmsLVAge;
}
float BMSData::getBMSLVCURRENT(){
    return bmsLVCurrent;
}
float BMSData::getBMSHVTotalTemperature(){
    return bmsHVTotalTemperature;
}
float BMSData::getBMSLVTotalTemperature(){
    return bmsLVTotalTemperature;
}
float BMSData::getBMSHVTotalVoltage(){
    return bmsHVTotalVoltage;
}
float BMSData::getBMSLVTotalVoltage(){
    return bmsLVTotalVoltage;
}