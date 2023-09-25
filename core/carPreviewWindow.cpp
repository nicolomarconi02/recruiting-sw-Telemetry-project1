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
        ImGui::Image((void*)(intptr_t)imageCar.image_texture, ImVec2(imageCar.image_width, imageCar.image_height));
        float xMax = ImGui::GetItemRectMax().x;
        float xMin = ImGui::GetItemRectMin().x;
        float imDim = xMax-xMin;
        if(ImGui::IsItemHovered()){
            ImGuiIO& io = ImGui::GetIO();
            ImGui::BeginTooltip();
            if((io.MousePos.x < (xMin + imDim * 1/3))){
                ImGui::Text("MOTOR");
                ImGui::Text("motorState: %.2f%%", motorData.motorState * 100);
                ImGui::Text("motorTemperature: %.2f °C", motorData.motorTemperature);
                ImGui::Text("inverterState: %.2f%%", motorData.inverterState * 100);
                ImGui::Text("inverterTemperature: %.2f °C", motorData.inverterTemperature);

            }
            else if((io.MousePos.x >= (xMin + imDim * 1/3)) && (io.MousePos.x < (xMin + imDim * 2/3))){
                ImGui::Text("ELECTRONIC");
                ImGui::Text("BMSHVVoltage: %.2f V", bmsData.bmsHVTotalVoltage);
                ImGui::Text("BMSHVTemperature: %.2f °C", bmsData.bmsHVTotalTemperature);
                ImGui::Text("BMSLVCurrent: %.2f A", bmsData.bmsLVCurrent);
                ImGui::Text("BMSLVVoltage: %.2f V", bmsData.bmsLVTotalVoltage);
                ImGui::Text("BMSLVTemperature: %.2f °C", bmsData.bmsLVTotalTemperature);
            }
            else{
                ImGui::Text("TYRE");
                if(ImGui::BeginTable("TYREINFO", 2, ImGuiTableFlags_SizingFixedSame)){
                    for(int i = 0; i < tyreData.numTyres; i++){
                        ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 100.0f);  
                        ImGui::TableNextColumn();           
                        switch (i)
                        {
                        case 0:
                            ImGui::Text("FRONT LEFT");
                            break;
                        case 1:
                            ImGui::Text("FRONT RIGHT");
                            break;
                        case 2:
                            ImGui::Text("REAR LEFT");
                            break;
                        case 3:
                            ImGui::Text("REAR RIGHT");
                            break;
                        default:
                            break;
                        }     
                        ImGui::Text("State: %.2f%%", tyreData.tyresState[i] * 100);
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