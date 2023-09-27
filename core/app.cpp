#include "app.h"

using namespace ImGui;

void app_render(DataBase* dataBase){
    car_preview(dataBase);
    track_session(dataBase);
    electronic(dataBase);
    tyre(dataBase);
    motor(dataBase);
    errors(dataBase);
    profile(dataBase);
}