#include "temperature.h"

void TemperatureData::generateData(){
    srand(time(NULL));

    for(int i = 0; i < numCellHV; i++){
        float gen = (float) (20 + rand() % 20) + (((float) rand())/((float)RAND_MAX));
        bmsHVTemperature.push_back(gen);
        bmsHVTotalTemperature += gen;
        bmsHVTotalTemperature = bmsHVTotalTemperature / numCellHV;
    }
    for(int i = 0; i < numCellLV; i++){
        float gen = (float) (20 + rand() % 30) + (((float) rand())/((float)RAND_MAX));
        bmsLVTemperature.push_back(gen);
        bmsLVTotalTemperature += gen;
        bmsLVTotalTemperature = bmsLVTotalTemperature / numCellLV;
    }
    for(int i = 0; i < numTyres; i++){
        float gen = (float) (40 + rand() % 110) + (((float) rand())/((float)RAND_MAX));
        tyresTemperature.push_back(gen);
    }
    motorTemperature = (float) (20 + rand() % 60) + (((float) rand())/((float)RAND_MAX));
    inverterTemperature = (float) (20 + rand() % 50) + (((float) rand())/((float)RAND_MAX));
}