#include "bms.h"

void BMSData::initializeData(){
    srand(time(NULL));

    for(int i = 0; i < numCellHV; i++){
        float gen = generateRandomData(1, 4);
        bmsHVVoltage.push_back(gen);
        bmsHVTotalVoltage += gen;
        gen = generateRandomData(20, 40);
        bmsHVTemperature.push_back(gen);
        bmsHVTotalTemperature += gen;
    }
    for(int i = 0; i < numCellLV; i++){
        float gen = generateRandomData(1, 4);
        bmsLVVoltage.push_back(gen);
        bmsLVTotalVoltage += gen;
        gen = generateRandomData(20, 50);
        bmsLVTemperature.push_back(gen);
        bmsLVTotalTemperature += gen;
    }
    bmsHVAge = generateRandomData(0, 500);
    bmsLVAge = generateRandomData(0, 500);
    bmsLVCurrent = generateRandomData(0, 30);
    bmsHVTotalTemperature = (float) bmsHVTotalTemperature / numCellHV;
    bmsLVTotalTemperature = (float) bmsLVTotalTemperature / numCellLV;
}