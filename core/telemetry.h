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

class TelemetryData : public Data {
public:
    vector<vector<TelemetryData>> telemetryDataPerLap;  // Stores telemetry data for multiple laps
    TrackData* trackData = NULL;  // Pointer to a TrackData object

    // Default constructor
    TelemetryData() {
        setnLap(5);  // Set the number of laps to 5
        initializeData();  // Initialize telemetry data
        trackData = new TrackData("Hockenheimring", "Hockenheim2012.jpg");  // Create a TrackData object
    }

    // Constructor with parameters
    TelemetryData(string trackName, string path, int n) {
        setnLap(n);  // Set the number of laps to the provided value
        initializeData();  // Initialize telemetry data
        trackData = new TrackData(trackName, path);  // Create a TrackData object with provided parameters
    }

    // Constructor with telemetry data parameters
    TelemetryData(float t, float s, int r) {
        lapTime = t;  // Set lap time
        speed = s;    // Set speed in km/h
        rpm = r;      // Set RPM
    }

    // Getter methods for telemetry data
    float getlapTime();
    float getSpeed();
    int getRPM();
    int getnLap();

    // Setter methods for telemetry data
    void setlapTime(float);
    void setSpeed(float);
    void setRPM(float);
    void setnLap(int);

    // Initialize telemetry data for multiple laps
    void initializeData();

    // Set up track data with a track name and image path
    void setupTrack(string, string);

private:
    float lapTime;  // Lap time
    float speed;    // Speed in km/h
    int rpm;        // RPM
    int nLap;       // Number of laps
};


#endif