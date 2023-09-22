#include "voltage.h"

void VoltageData::generateData(){
    srand(time(NULL));

    for(int i = 0; i < numCellHV; i++){
        float gen = (float) (1 + rand() % 3) + (((float) rand())/((float)RAND_MAX));
        bmsHVVoltage.push_back(gen);
        bmsHVTotalVoltage += gen;
    }
    for(int i = 0; i < numCellLV; i++){
        float gen = (float) (1+ rand() % 3) + (((float) rand())/((float)RAND_MAX));
        bmsLVVoltage.push_back(gen);
        bmsLVTotalVoltage += gen;
    }
}