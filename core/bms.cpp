#include "bms.h"

// Initialize the BMSData class.
void BMSData::initializeData() {
    // Seed the random number generator.
    srand(time(NULL));

    // Initialize data for high voltage cells.
    for (int i = 0; i < numCellHV; i++) {
        // Generate a random voltage value between 0 and 4 for high voltage cells.
        float gen = generateRandomData(0, 4);
        // Add the generated voltage value to the vector bmsHVVoltage.
        bmsHVVoltage.push_back(gen);
        // Update the total high voltage temperature.
        setBMSHVTotalVoltage(gen);

        // Generate a random temperature value between 20 and 40 for high voltage cells.
        gen = generateRandomData(20, 40);
        // Add the generated temperature value to the vector bmsHVTemperature.
        bmsHVTemperature.push_back(gen);
        // Update the total high voltage temperature.
        setBMSHVTotalTemperature(gen);
    }

    // Initialize data for low voltage cells.
    for (int i = 0; i < numCellLV; i++) {
        // Generate a random voltage value between 0 and 4 for low voltage cells.
        float gen = generateRandomData(0, 4);
        // Add the generated voltage value to the vector bmsLVVoltage.
        bmsLVVoltage.push_back(gen);
        // Update the total low voltage temperature.
        setBMSLVTotalVoltage(gen);

        // Generate a random temperature value between 20 and 50 for low voltage cells.
        gen = generateRandomData(20, 50);
        // Add the generated temperature value to the vector bmsLVTemperature.
        bmsLVTemperature.push_back(gen);
        // Update the total low voltage temperature.
        setBMSLVTotalTemperature(gen);
    }

    // Generate random values for BMS ages and current.
    setBMSHVAGE(generateRandomData(0, 500));
    setBMSLVAGE(generateRandomData(0, 500));
    setBMSLVCURRENT(generateRandomData(0, 30));

    // Calculate average temperatures for high and low voltage cells.
    bmsHVTotalTemperature = (float)getBMSHVTotalTemperature() / getNumCellHV();
    bmsLVTotalTemperature = (float)getBMSLVTotalTemperature() / getNumCellLV();
}

// Set error conditions based on BMS data.
void BMSData::setError() {
    // Check and set error messages for high voltage cells.
    if ((bmsHVTotalVoltage * 100) / (numCellHV * 4) < 15) {
        error.electronicErrorList.push_back("CRITICAL BMS HV VOLTAGE");
    } else if ((bmsHVTotalVoltage * 100) / (numCellHV * 4) >= 15 && bmsHVTotalVoltage / numCellHV < 30) {
        error.electronicErrorList.push_back("WARNING BMS HV VOLTAGE");
    }

    // Check and set error messages for low voltage cells.
    if ((bmsLVTotalVoltage * 100) / (numCellLV * 4) < 15) {
        error.electronicErrorList.push_back("CRITICAL BMS LV VOLTAGE");
    } else if ((bmsLVTotalVoltage * 100) / (numCellLV * 4) >= 15 && bmsLVTotalVoltage / numCellLV < 30) {
        error.electronicErrorList.push_back("WARNING BMS LV VOLTAGE");
    }

    // Check and set error messages for high voltage temperature.
    if (bmsHVTotalTemperature > 35) {
        error.electronicErrorList.push_back("CRITICAL BMS HV TEMPERATURE");
    } else if (bmsHVTotalTemperature > 30 && bmsHVTotalTemperature <= 35) {
        error.electronicErrorList.push_back("WARNING BMS HV TEMPERATURE");
    }

    // Check and set error messages for low voltage temperature.
    if (bmsLVTotalTemperature > 45) {
        error.electronicErrorList.push_back("CRITICAL BMS LV TEMPERATURE");
    } else if (bmsLVTotalTemperature > 40 && bmsLVTotalTemperature <= 45) {
        error.electronicErrorList.push_back("WARNING BMS LV TEMPERATURE");
    }
}

// Define setter functions for BMS data.
void BMSData::setNumCellHV(int v) {
    numCellHV = v;
}
void BMSData::setNumCellLV(int v) {
    numCellLV = v;
}
void BMSData::setBMSHVAGE(float v) {
    bmsHVAge = v;
}
void BMSData::setBMSLVAGE(float v) {
    bmsLVAge = v;
}
void BMSData::setBMSLVCURRENT(float v) {
    bmsLVCurrent = v;
}
void BMSData::setBMSHVTotalTemperature(float v) {
    bmsHVTotalTemperature += v;
}
void BMSData::setBMSLVTotalTemperature(float v) {
    bmsLVTotalTemperature += v;
}
void BMSData::setBMSHVTotalVoltage(float v) {
    bmsHVTotalVoltage += v;
}
void BMSData::setBMSLVTotalVoltage(float v) {
    bmsLVTotalVoltage += v;
}

// Define getter functions for BMS data.
int BMSData::getNumCellHV() {
    return numCellHV;
}
int BMSData::getNumCellLV() {
    return numCellLV;
}
float BMSData::getBMSHVAGE() {
    return bmsHVAge;
}
float BMSData::getBMSLVAGE() {
    return bmsLVAge;
}
float BMSData::getBMSLVCURRENT() {
    return bmsLVCurrent;
}
float BMSData::getBMSHVTotalTemperature() {
    return bmsHVTotalTemperature;
}
float BMSData::getBMSLVTotalTemperature() {
    return bmsLVTotalTemperature;
}
float BMSData::getBMSHVTotalVoltage() {
    return bmsHVTotalVoltage;
}
float BMSData::getBMSLVTotalVoltage() {
    return bmsLVTotalVoltage;
}