#include "app.h"

void motor(DataBase* dataBase) {
    if (ImGui::Begin("Motor", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        // Check if a collapsible section for "Motor" is open
        if (ImGui::CollapsingHeader("Motor")) {
            // Display motor-related information
            ImGui::Text("motorAge: %.2f Km", dataBase->motorData.getMotorAge());
            ImGui::Text("motorState: %.2f%%", dataBase->motorData.getMotorState() * 100);
            ImGui::Text("motorTemperature: %.2f °C", dataBase->motorData.getMotorTemperature());
        }
        
        // Check if a collapsible section for "Inverter" is open
        if (ImGui::CollapsingHeader("Inverter")) {
            // Display inverter-related information
            ImGui::Text("inverterAge: %.2f Km", dataBase->motorData.getInverterAge());
            ImGui::Text("inverterState: %.2f%%", dataBase->motorData.getInverterState() * 100);
            ImGui::Text("inverterTemperature: %.2f °C", dataBase->motorData.getInverterTemperature());
        }
        
        // End the ImGui window
        ImGui::End();
    }
}