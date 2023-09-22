#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class TemperatureData{
    public:
        int numCellHV = 108;
        int numCellLV = 4;
        int numTyres = 4;

        float motorTemperature;
        float inverterTemperature;
        float bmsHVTotalTemperature;
        float bmsLVTotalTemperature;

        vector<float> bmsHVTemperature;
        vector<float> bmsLVTemperature;
        vector<float> tyresTemperature;

        TemperatureData(){
            generateData();
        }

        void generateData();
};