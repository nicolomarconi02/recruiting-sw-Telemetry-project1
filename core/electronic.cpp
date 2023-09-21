#include "app.h"

void electronic(VoltageData voltageData){
    if(ImGui::Begin("Electronic", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("BMSHVVOLTAGE %.2f", voltageData.bmsHVVoltage[0]);
        if(ImGui::BeginTable("BMSHVVOLTAGE", 12)){
            for(int row = 0; row < 9; row++){
                ImGui::TableNextRow();
                for(int column = 0; column < 12; column++){
                    ImGui::TableSetColumnIndex(column);
                    ImGui::Text("%.2f", voltageData.bmsHVVoltage[12*row + column]);
                }
            }
            ImGui::EndTable();
        }
        ImGui::End();
    }
}