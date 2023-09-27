#include "app.h"

using namespace ImGui;

// Define a function named app_render that takes a pointer to a DataBase object as a parameter.
void app_render(DataBase* dataBase) {
    
    // Render the car preview section using the car_preview function.
    car_preview(dataBase);

    // Render the track session section using the track_session function.
    track_session(dataBase);

    // Render the electronic section using the electronic function.
    electronic(dataBase);

    // Render the tyre section using the tyre function.
    tyre(dataBase);

    // Render the motor section using the motor function.
    motor(dataBase);

    // Render the errors section using the errors function.
    errors(dataBase);

    // Render the profile section using the profile function.
    profile(dataBase);
}