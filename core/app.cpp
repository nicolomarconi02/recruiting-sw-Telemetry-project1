#include "app.h"

using namespace ImGui;

void app_render(DataBase* dataBase){
    
    car_preview(dataBase);
    track_session(dataBase);
    electronic(dataBase);
    tyre(dataBase);
    motor(dataBase);
    errors();
    profile(dataBase);
    // car_state();
    // profile();

    // if(Begin("FRAME", NULL, NULL)){
    //     End();
    // }
    // if(Begin("Menu 1")){
    //     Text("Project 1");
    //     Button("prova");
    //     const float my_values[] = { 0.2f, 0.1f, 1.0f, 0.5f, 0.9f, 2.2f };
    //     PlotLines("ProvaDati", my_values, IM_ARRAYSIZE(my_values));
    //     if(BeginChild("TextArea")){
    //         for(int i = 0; i < 20; i++){
    //             Text("%d ciao", i);
    //         }
    //         EndChild();
    //     }
    //     End();
    // }
    // if(Begin("Menu 2")){
    //     Text("menu 2");
    //     End();
    // }

}