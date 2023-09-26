#include "app.h"

void motor(DataBase* dataBase){
    if(ImGui::Begin("Motor", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("Motor")){
            ImGui::Text("motorAge: %.2f Km", dataBase->motorData.motorAge);
            ImGui::Text("motorState: %.2f%%", dataBase->motorData.motorState * 100);
            ImGui::Text("motorTemperature: %.2f °C", dataBase->motorData.motorTemperature);
        }
        if(ImGui::CollapsingHeader("Inverter")){
            ImGui::Text("inverterAge: %.2f Km", dataBase->motorData.inverterAge);
            ImGui::Text("inverterState: %.2f%%", dataBase->motorData.inverterState * 100);
            ImGui::Text("inverterTemperature: %.2f °C", dataBase->motorData.inverterTemperature);
        }
        ImGui::End();
    }
}