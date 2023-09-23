#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "data.h"

using namespace std;

class TelemetryData : public Data{
public:
    vector<vector<TelemetryData>> telemetryDataPerLap;
    
    TelemetryData(){
        initializeData();
    }

    TelemetryData(float t, float s, int r){
        lapTime = t;
        speed = s; 
        rpm = r;
    }

    float getlapTime();
    float getSpeed();
    int getRPM();
    void initializeData();

private:
    float lapTime;
    float speed;  // km/h
    int rpm;
};