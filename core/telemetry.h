#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class TelemetryData {
public:
    vector<vector<TelemetryData>> telemetryDataPerLap;
    
    TelemetryData(){
        generateData();
    }

    TelemetryData(float t, float s, int r){
        lapTime = t;
        speed = s; 
        rpm = r;
    }

    float getlapTime();
    float getSpeed();
    int getRPM();
    void generateData();

private:
    float lapTime;
    float speed;  // km/h
    int rpm;
};