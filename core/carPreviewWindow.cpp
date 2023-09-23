#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include "imgui/imgui.h"

Image imageCar("../data/car.png");
bool isCarOpen = false;

void car_preview(BMSData bmsData, TyreData tyreData, MotorData motorData){
    if(ImGui::Begin("Car Preview", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("CAR IMAGE");
        if(!isCarOpen){
            imageCar.LoadTextureFromFile();
            isCarOpen = true;
        }
        ImGui::Text("height: %d width: %d", imageCar.image_height, imageCar.image_width);
        ImGui::Image((void*)(intptr_t)imageCar.image_texture, ImVec2(imageCar.image_width, imageCar.image_height));
        float xMax = ImGui::GetItemRectMax().x;
        float xMin = ImGui::GetItemRectMin().x;
        float imDim = xMax-xMin;
        if(ImGui::IsItemHovered()){
            ImGuiIO& io = ImGui::GetIO();
            ImGui::BeginTooltip();
            if((io.MousePos.x < (xMin + imDim * 1/3))){
                ImGui::Text("MOTOR");
                ImGui::Text("motorTemperature: %.2f °C", motorData.motorTemperature);
                ImGui::Text("inverterTemperature: %.2f °C", motorData.inverterTemperature);

            }
            else if((io.MousePos.x >= (xMin + imDim * 1/3)) && (io.MousePos.x < (xMin + imDim * 2/3))){
                ImGui::Text("ELECTRONIC");
                ImGui::Text("BMSHVVoltage: %.2f V", bmsData.bmsHVTotalVoltage);
                ImGui::Text("BMSHVTemperature: %.2f °C", bmsData.bmsHVTotalTemperature);
                ImGui::Text("BMSLVVoltage: %.2f V", bmsData.bmsLVTotalVoltage);
                ImGui::Text("BMSLVTemperature: %.2f °C", bmsData.bmsLVTotalTemperature);
            }
            else{
                ImGui::Text("TYRE");
                if(ImGui::BeginTable("BMSHVVOLTAGE", 2, ImGuiTableFlags_SizingFixedSame)){
                    for(int i = 0; i < tyreData.numTyres; i++){
                        ImGui::TableNextColumn();                
                        ImGui::Text("%.2f C°", tyreData.tyresTemperature[i]);
                        // ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(bmsData.bmsHVVoltage[i]));
                    }
                    ImGui::EndTable();
                }
            }

            ImGui::EndTooltip();
        }
        ImGui::End();
    }
}