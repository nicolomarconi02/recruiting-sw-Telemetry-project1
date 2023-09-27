#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include "imgui/imgui.h"

Image imageCar("../data/car.png");
bool isCarOpen = false;

void car_preview(DataBase* dataBase){
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
                ImGui::Text("motorState: %.2f%%", dataBase->motorData.getMotorState() * 100);
                ImGui::Text("motorTemperature: %.2f °C", dataBase->motorData.getMotorTemperature());
                ImGui::Text("inverterState: %.2f%%", dataBase->motorData.getInverterState() * 100);
                ImGui::Text("inverterTemperature: %.2f °C", dataBase->motorData.getInverterTemperature());

            }
            else if((io.MousePos.x >= (xMin + imDim * 1/3)) && (io.MousePos.x < (xMin + imDim * 2/3))){
                ImGui::Text("ELECTRONIC");
                ImGui::Text("BMSHVVoltage: %.2f V", dataBase->bmsData.getBMSHVTotalVoltage());
                ImGui::Text("BMSHVTemperature: %.2f °C", dataBase->bmsData.getBMSHVTotalTemperature());
                ImGui::Text("BMSLVCurrent: %.2f A", dataBase->bmsData.getBMSLVCURRENT());
                ImGui::Text("BMSLVVoltage: %.2f V", dataBase->bmsData.getBMSLVTotalVoltage());
                ImGui::Text("BMSLVTemperature: %.2f °C", dataBase->bmsData.getBMSLVTotalTemperature());
            }
            else{
                ImGui::Text("TYRE");
                if(ImGui::BeginTable("TYREINFO", 2, ImGuiTableFlags_SizingFixedSame)){
                    for(int i = 0; i < dataBase->tyreData.numTyres; i++){
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
                        ImGui::Text("State: %.2f%%", dataBase->tyreData.tyresState[i] * 100);
                        ImGui::Text("%.2f C°", dataBase->tyreData.tyresTemperature[i]);
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