#include <GL/glew.h>
#include "app.h"
#include "image.h"

Image imageCar("../data/car.png");
bool isCarOpen = false;

void car_preview(){
    if(ImGui::Begin("Car Preview", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("CAR IMAGE");
        if(!isCarOpen){
            imageCar.LoadTextureFromFile();
            isCarOpen = true;
        }
        ImGui::Image((void*)(intptr_t)imageCar.image_texture, ImVec2(imageCar.image_width/3, imageCar.image_height/3));
        ImGui::End();
    }
}