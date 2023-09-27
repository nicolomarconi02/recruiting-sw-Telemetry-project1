#ifndef TRACK_H
#define TRACK_H


#include <iostream>
#include <string.h>
#include <memory>
#include "image.h"


using namespace std;

class TrackData{
    public:
        // unique_ptr<Image> image;
        Image* image = NULL;
        TrackData(const char* name, const char* path){
            setTrackName(name);
            setImagePath(path);
            // image = make_unique<Image>(path);
            cout << "TRACKDATA CONSTR name " << name << " path " << path << endl;
            fflush(stdout);
            image = new Image(path);
        }

        const char* getTrackName();
        char* getImagePath();
        void setTrackName(const char*);
        void setImagePath(const char*);

    private:
        char trackName[64];
        char imagePath[64];
};

#endif