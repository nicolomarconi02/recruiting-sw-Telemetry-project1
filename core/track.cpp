#include "track.h"

using namespace std;

char* TrackData::getTrackName(){
    return trackName;
}

char* TrackData::getImagePath(){
    return imagePath;
}

void TrackData::setTrackName(const char* track){
    strcpy(trackName, track);
    // trackName = track;
}
        
void TrackData::setImagePath(const char* path){
    strcpy(imagePath, path);
    // imagePath = path;
}