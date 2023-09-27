#include <iostream>
#include <vector>
#include "data.h"

using namespace std;

// Define a class named BMSData that inherits from the Data class.
class BMSData : public Data {
public:
    // Public member variables for storing BMS data.
    vector<float> bmsHVVoltage;
    vector<float> bmsLVVoltage;
    vector<float> bmsHVTemperature;
    vector<float> bmsLVTemperature;

    // Constructor for the BMSData class.
    BMSData() {
        // Initialize BMS data and set error conditions during object creation.
        initializeData();
        setError();
    }

    // Function to initialize BMS data.
    void initializeData();

    // Function to set error conditions based on BMS data.
    void setError();

    // Setter functions for modifying various BMS data attributes.
    void setNumCellHV(int);
    void setNumCellLV(int);
    void setBMSHVAGE(float);
    void setBMSLVAGE(float);
    void setBMSLVCURRENT(float);
    void setBMSHVTotalTemperature(float);
    void setBMSLVTotalTemperature(float);
    void setBMSHVTotalVoltage(float);
    void setBMSLVTotalVoltage(float);

    // Getter functions for retrieving various BMS data attributes.
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
    // Private member variables representing BMS data.
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
