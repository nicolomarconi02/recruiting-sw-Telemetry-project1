#include "app.h"

void motor(MotorData motorData){
    if(ImGui::Begin("Motor", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("Motor")){
            ImGui::Text("motorAge: %.2f Km", motorData.motorAge);
            ImGui::Text("motorState: %.2f%%", motorData.motorState * 100);
            ImGui::Text("motorTemperature: %.2f °C", motorData.motorTemperature);
        }
        if(ImGui::CollapsingHeader("Inverter")){
            ImGui::Text("inverterAge: %.2f Km", motorData.inverterAge);
            ImGui::Text("inverterState: %.2f%%", motorData.inverterState * 100);
            ImGui::Text("inverterTemperature: %.2f °C", motorData.inverterTemperature);
        }
        ImGui::End();
    }
}