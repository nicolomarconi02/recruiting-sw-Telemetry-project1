#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

class BMSData : public Data{
    public:
        vector<float> bmsHVVoltage;
        vector<float> bmsLVVoltage;
        vector<float> bmsHVTemperature;
        vector<float> bmsLVTemperature;

        BMSData(){
            initializeData();
            setError();
        }

        void initializeData();
        void setError();

        void setNumCellHV(int);
        void setNumCellLV(int);
        void setBMSHVAGE(float);
        void setBMSLVAGE(float);
        void setBMSLVCURRENT(float);
        void setBMSHVTotalTemperature(float);
        void setBMSLVTotalTemperature(float);
        void setBMSHVTotalVoltage(float);
        void setBMSLVTotalVoltage(float);

        int getNumCellHV();
        int getNumCellLV();
        float getBMSHVAGE();
        float getBMSLVAGE();
        float getBMSLVCURRENT();
        float getBMSHVTotalTemperature();
        float getBMSLVTotalTemperature();
        float getBMSHVTotalVoltage();
        float getBMSLVTotalVoltage();
    private:
        int numCellHV = 108;
        int numCellLV = 4;
        float bmsHVAge;
        float bmsLVAge;
        float bmsLVCurrent;
        float bmsHVTotalTemperature;
        float bmsLVTotalTemperature;
        float bmsHVTotalVoltage = 0;
        float bmsLVTotalVoltage = 0;
};