#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class VoltageData{
    public:
        int numCellHV = 108;
        int numCellLV = 4;
        vector<float> bmsHVVoltage;
        vector<float> bmsLVVoltage;
        float bmsHVTotalVoltage = 0;
        float bmsLVTotalVoltage = 0;

        VoltageData(){
            generateData();
        }

        void generateData();
};