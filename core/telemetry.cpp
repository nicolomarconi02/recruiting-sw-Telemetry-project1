#include "telemetry.h"

using namespace std;

void TelemetryData::initializeData(){

    int numDataPoints = 16;  // Numero di punti dati (curve del tracciato)
    int timeInterval = 5;    // Intervallo di tempo tra i punti dati (secondi)
    srand(time(NULL));
    for(int i = 0; i < getnLap(); i++){
        vector<TelemetryData> telemetryData;
        for (int j = 0; j < numDataPoints; j++) {
            float time = j * timeInterval;
            float speed = generateRandomData(40, 200);  // Velocità casuale tra 40 e 200 km/h
            int rpm = generateRandomData(2000, 7000);      // RPM casuale tra 2000 e 7000
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