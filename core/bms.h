#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class BMSData : public Data{
    public:
        int numCellHV = 108;
        int numCellLV = 4;
        vector<float> bmsHVVoltage;
        vector<float> bmsLVVoltage;
        vector<float> bmsHVTemperature;
        vector<float> bmsLVTemperature;
        float bmsHVAge;
        float bmsLVAge;
        float bmsLVCurrent;
        float bmsHVTotalTemperature;
        float bmsLVTotalTemperature;
        float bmsHVTotalVoltage = 0;
        float bmsLVTotalVoltage = 0;

        BMSData(){
            initializeData();
        }

        void initializeData();
};