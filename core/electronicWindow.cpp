#include "app.h"
#include <cmath>

ImU32 setBgColor(float data){
    ImU32 color;
    int val = round(data);

    switch (val)
    {
    case 5:
    case 4:
        color = ImGui::GetColorU32(ImVec4(5/255.0f, 163/255.0f, 5/255.0f, 1.0f)); //green
        break;
    case 3:
        color = ImGui::GetColorU32(ImVec4(202/255.0f, 209/255.0f, 2/255.0f, 1.0f)); //yellow
        break;
    case 2:
        color = ImGui::GetColorU32(ImVec4(209/255.0f, 144/255.0f, 2/255.0f, 1.0f)); //orange
        break;
    case 1:
    case 0:
        color = ImGui::GetColorU32(ImVec4(209/255.0f, 19/255.0f, 2/255.0f, 1.0f)); //red
        break;
    default:
        color = ImGui::GetColorU32(ImVec4(0.3f, 0.3f, 0.7f, 0.65f));
        break;
    }
}

void electronic(BMSData bmsData){
    if(ImGui::Begin("Electronic", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("BMSHVVOLTAGE (V)")){
            ImGui::Text("BMSHVVOLTAGE %.2f", bmsData.bmsHVTotalVoltage);
            if(ImGui::BeginTable("BMSHVVOLTAGE", 12, ImGuiTableFlags_SizingFixedSame)){
                ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 40.0f);  
                for(int i = 0; i < bmsData.numCellHV; i++){
                    ImGui::TableNextColumn();                
                    ImGui::Text("%.2f", bmsData.bmsHVVoltage[i]);
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(bmsData.bmsHVVoltage[i]));
                }
                ImGui::EndTable();
            }
        }
        if(ImGui::CollapsingHeader("BMSLVVOLTAGE (V)")){
            ImGui::Text("BMSHVVOLTAGE %.2f", bmsData.bmsLVTotalVoltage);
            if(ImGui::BeginTable("BMSHVVOLTAGE", 4, ImGuiTableFlags_SizingFixedSame)){
                ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 40.0f);  
                for(int i = 0; i < bmsData.numCellLV; i++){
                    ImGui::TableNextColumn();                
                    ImGui::Text("%.2f", bmsData.bmsLVVoltage[i]);
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(bmsData.bmsLVVoltage[i]));
                }
                ImGui::EndTable();
            }
        }

        ImGui::End();
    }
}