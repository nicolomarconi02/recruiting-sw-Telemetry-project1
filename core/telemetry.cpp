#include "telemetry.h"

using namespace std;

void TelemetryData::initializeData() {
    // Initialize telemetry data for a race track

    int numDataPoints = 16;  // Number of data points (track curves)
    int timeInterval = 5;    // Time interval between data points (seconds)
    srand(time(NULL));       // Seed the random number generator

    // Loop through each lap of the race
    for (int i = 0; i < getnLap(); i++) {
        vector<TelemetryData> telemetryData; // Create a vector to store telemetry data for one lap

        // Generate telemetry data for each curve on the track
        for (int j = 0; j < numDataPoints; j++) {
            float time = j * timeInterval;                   // Time increases for each data point
            float speed = generateRandomData(40, 200);       // Random speed between 40 and 200 km/h
            int rpm = generateRandomData(2000, 7000);        // Random RPM between 2000 and 7000
            TelemetryData data(time, speed, rpm);            // Create telemetry data object
            telemetryData.push_back(data);                   // Add telemetry data to the lap's vector
        }

        telemetryDataPerLap.push_back(telemetryData);        // Add the lap's telemetry data to the overall vector
    }
}

float TelemetryData::getlapTime(){
    return lapTime;
}

float TelemetryData::getSpeed(){
    return speed;
}

int TelemetryData::getRPM(){
    return rpm;
}

int TelemetryData::getnLap(){
    return nLap;
}

void TelemetryData::setlapTime(float time){
    lapTime = time;
}
void TelemetryData::setSpeed(float spd){
    speed = spd;
}
void TelemetryData::setRPM(float r){
    rpm = r;
}
void TelemetryData::setnLap(int n){
    nLap = n;
}