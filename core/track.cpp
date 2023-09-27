#include "track.h"

using namespace std;

string TrackData::getTrackName(){
    return trackName;
}

string TrackData::getImagePath(){
    return imagePath;
}

void TrackData::setTrackName(string track){
    trackName = track;
}
        
void TrackData::setImagePath(string path){
    imagePath = path;
}