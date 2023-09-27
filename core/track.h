#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
#include <memory>
#include "image.h"

using namespace std;

class TrackData{
    public:
        // unique_ptr<Image> image;
        bool isImageOpen = false;
        Image* image = NULL;
        TrackData(string name, string path){
            setTrackName(name);
            setImagePath(path);
            // image = make_unique<Image>(path);
            cout << "TRACKDATA CONSTR name " << name << " path " << path << endl;
            fflush(stdout);
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