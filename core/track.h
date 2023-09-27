#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
#include <memory>
#include "image.h"

using namespace std;

class TrackData{
    public:
        bool isImageOpen = false;
        Image* image = NULL;
        TrackData(string name, string path){
            setTrackName(name);
            setImagePath(path);
            image = new Image(path);
        }

        string getTrackName();
        string getImagePath();
        void setTrackName(string);
        void setImagePath(string);

    private:
        string trackName;
        string imagePath;
};

#endif