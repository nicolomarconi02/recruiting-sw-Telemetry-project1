#include "voltage.h"

// void VoltageData::generateData(){
//     srand(time(NULL));
//     int numCel = 30;
    
//     for(int i = 0; i < numCel; i++){
//         VoltageData voltage(rand() % 50, rand() % );
//         tableVoltage.push_back(voltage);
//     }
// }

// float VoltageData::getCellVoltage(){
//     return cellVoltage;
// }

void VoltageData::generateData(){
    srand(time(NULL));

    for(int i = 0; i < numCellHV; i++){
        float gen = (float) (350 + rand() % 111) + (((float) rand())/((float)RAND_MAX));
        bmsHVVoltage.push_back(gen);
    }
    for(int i = 0; i < numCellLV; i++){
        float gen = (float) (12 + rand() % 7) + (((float) rand())/((float)RAND_MAX));
        bmsLVVoltage.push_back(gen);
    }
}