#include "app.h"

void motor(DataBase* dataBase){
    if(ImGui::Begin("Motor", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("Motor")){
            ImGui::Text("motorAge: %.2f Km", dataBase->motorData.getMotorAge());
            ImGui::Text("motorState: %.2f%%", dataBase->motorData.getMotorState() * 100);
            ImGui::Text("motorTemperature: %.2f °C", dataBase->motorData.getMotorTemperature());
        }
        if(ImGui::CollapsingHeader("Inverter")){
            ImGui::Text("inverterAge: %.2f Km", dataBase->motorData.getInverterAge());
            ImGui::Text("inverterState: %.2f%%", dataBase->motorData.getInverterState() * 100);
            ImGui::Text("inverterTemperature: %.2f °C", dataBase->motorData.getInverterTemperature());
        }
        ImGui::End();
    }
}