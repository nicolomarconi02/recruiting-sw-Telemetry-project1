#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include "telemetry.h"

using namespace std;

void TelemetryData::generateData(){

    int numDataPoints = 16;  // Numero di punti dati (curve del tracciato)
    int timeInterval = 5;    // Intervallo di tempo tra i punti dati (secondi)
    int numLap = 5;
    srand(time(NULL));

    for(int i = 0; i < numLap; i++){
        vector<TelemetryData> telemetryData;
        for (int j = 0; j < numDataPoints; j++) {
            float time = j * timeInterval;
            float speed = 140 + (rand() % (200 - 140 + 1));  // Velocità casuale tra 140 e 200 km/h
            int rpm = 2000 + rand() % (7000 - 2000 + 1);      // RPM casuale tra 2000 e 7000
            TelemetryData data(time, speed, rpm);
            telemetryData.push_back(data);
        }
        telemetryDataPerLap.push_back(telemetryData);
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