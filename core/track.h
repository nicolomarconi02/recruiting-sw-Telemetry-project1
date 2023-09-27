#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <string>
#include <memory>
#include "image.h"

using namespace std;

class TrackData{
public:
    // Public member variables
    bool isImageOpen = false;  // Indicates whether the track's image is open or not
    Image* image = NULL;       // Pointer to an Image object associated with the track

    // Constructor: Initializes the object with a track name and image path
    TrackData(string name, string path){
        setTrackName(name);    // Call the setter to set the track name
        setImagePath(path);    // Call the setter to set the image path
        image = new Image(path);  // Create an Image object based on the provided path
    }

    // Getter method for retrieving the track name
    string getTrackName();

    // Getter method for retrieving the image path
    string getImagePath();

    // Setter method for setting the track name
    void setTrackName(string);

    // Setter method for setting the image path
    void setImagePath(string);

private:
    // Private member variables
    string trackName;  // Stores the name of the track
    string imagePath;  // Stores the path to the track's image
};


#endif