#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include "imgui/imgui.h"

Image imageCar("../data/car.png");
bool isCarOpen = false;

void car_preview(){
    if(ImGui::Begin("Car Preview", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("CAR IMAGE");
        if(!isCarOpen){
            imageCar.LoadTextureFromFile();
            isCarOpen = true;
        }
        ImGui::Text("height: %d width: %d", imageCar.image_height, imageCar.image_width);
        ImGui::Image((void*)(intptr_t)imageCar.image_texture, ImVec2(imageCar.image_width, imageCar.image_height));
        if(ImGui::IsItemHovered()){
            ImGuiIO& io = ImGui::GetIO();
            ImGui::BeginTooltip();
            float xMax = ImGui::GetItemRectMax().x;
            float xMin = ImGui::GetItemRectMin().x;
            if((io.MousePos.x > xMin * 4/3) && (io.MousePos.x < xMax * 5/3)){
                ImGui::Text("ELECTRONIC");
            }
            else{
                ImGui::Text("TYRE");
            }
            ImGui::Text("x: %.2f y: %.2f", io.MousePos.x, io.MousePos.y);
            ImGui::Text("rectXMin: %.2f rectXMax: %.2f", xMin, xMax);

            ImGui::EndTooltip();
        }
        ImGui::End();
    }
}