#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include "imgui/imgui.h"

Image imageCar("../data/car.png");
bool isCarOpen = false;

void car_preview(VoltageData voltageData,TemperatureData temperatureData){
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
        if(ImGui::IsItemHovered()){
            ImGuiIO& io = ImGui::GetIO();
            ImGui::BeginTooltip();
            if((io.MousePos.x < xMax * 1/3)){
                ImGui::Text("MOTOR");
                ImGui::Text("motorTemperature: %.2f", temperatureData.motorTemperature);
                ImGui::Text("inverterTemperature: %.2f", temperatureData.inverterTemperature);

            }
            else if((io.MousePos.x > xMax * 1/3) && (io.MousePos.x < xMax * 2/3)){
                ImGui::Text("ELECTRONIC");
                ImGui::Text("BMSHVVoltage: %.2f", voltageData.bmsHVTotalVoltage);
                ImGui::Text("BMSHVTemperature: %.2f", temperatureData.bmsHVTotalTemperature);
                ImGui::Text("BMSLVVoltage: %.2f", voltageData.bmsLVTotalVoltage);
                ImGui::Text("BMSLVTemperature: %.2f", temperatureData.bmsLVTotalTemperature);
            }
            else{
                ImGui::Text("TYRE");
                if(ImGui::BeginTable("BMSHVVOLTAGE", 2, ImGuiTableFlags_SizingFixedSame)){
                    for(int i = 0; i < temperatureData.numTyres; i++){
                        ImGui::TableNextColumn();                
                        ImGui::Text("%.2f", temperatureData.tyresTemperature[i]);
                        // ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(voltageData.bmsHVVoltage[i]));
                    }
                    ImGui::EndTable();
                }
            }
            ImGui::Text("x: %.2f y: %.2f", io.MousePos.x, io.MousePos.y);
            ImGui::Text("rectXMin: %.2f rectXMax: %.2f", xMin, xMax);

            ImGui::EndTooltip();
        }
        ImGui::End();
    }
}