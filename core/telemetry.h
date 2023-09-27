#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <memory>
#include "data.h"
#include "track.h"

using namespace std;

class TelemetryData : public Data{
public:
    vector<vector<TelemetryData>> telemetryDataPerLap;
    TrackData* trackData = NULL;
    TelemetryData(){
        setnLap(5);
        initializeData();
        // trackData = make_unique<TrackData>("Hockenheimring", "Hockenheim2012.jpg");
        // TrackData track("Hockenheimring", "Hockenheim2012.jpg");
        // trackData.push_back(track);
        trackData = new TrackData("Hockenheimring", "Hockenheim2012.jpg");
    }

    TelemetryData(string trackName,string path, int n){
        setnLap(n);
        initializeData();
        // trackData = make_unique<TrackData>(trackName, path);
        trackData = new TrackData(trackName, path);
    }

    TelemetryData(float t, float s, int r){
        lapTime = t;
        speed = s; 
        rpm = r;
    }

    float getlapTime();
    float getSpeed();
    int getRPM();
    int getnLap();
    void setlapTime(float);
    void setSpeed(float);
    void setRPM(float);
    void setnLap(int);
    void initializeData();
    void setupTrack(string, string);

private:
    float lapTime;
    float speed;  // km/h
    int rpm;
    int nLap;
};

#endif