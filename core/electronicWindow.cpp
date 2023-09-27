#include "app.h"
#include <cmath>

// Function to set the background color based on a value (data)
ImU32 setBgColor(float data) {
    ImU32 color;
    int val = round(data);

    switch (val) {
        case 5:
        case 4:
            color = ImGui::GetColorU32(ImVec4(5/255.0f, 163/255.0f, 5/255.0f, 1.0f)); // Green
            break;
        case 3:
            color = ImGui::GetColorU32(ImVec4(202/255.0f, 209/255.0f, 2/255.0f, 1.0f)); // Yellow
            break;
        case 2:
            color = ImGui::GetColorU32(ImVec4(209/255.0f, 144/255.0f, 2/255.0f, 1.0f)); // Orange
            break;
        case 1:
        case 0:
            color = ImGui::GetColorU32(ImVec4(209/255.0f, 19/255.0f, 2/255.0f, 1.0f)); // Red
            break;
        default:
            color = ImGui::GetColorU32(ImVec4(0.3f, 0.3f, 0.7f, 0.65f)); // Default color
            break;
    }
    return color;
}

// Function to display electronic data in an ImGui window
void electronic(DataBase* dataBase) {
    if (ImGui::Begin("Electronic", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        if (ImGui::CollapsingHeader("BMSHV")) {
            // Display BMSHV information
            ImGui::Text("AGE %.2f Km", dataBase->bmsData.getBMSHVAGE());
            ImGui::ProgressBar(dataBase->bmsData.getBMSHVTotalVoltage() / (4 * dataBase->bmsData.getNumCellHV()), ImVec2(0.0f, 0.0f));
            ImGui::SameLine();
            ImGui::Text("BATTERY LEVEL");
            ImGui::Text("BMSHVTEMPERATURE %.2f °C", dataBase->bmsData.getBMSHVTotalTemperature());
            ImGui::Text("BMSHVVOLTAGE %.2f V", dataBase->bmsData.getBMSHVTotalVoltage());
            ImGui::Text("BMSHVVOLTAGE CELLS: (V)");
            
            // Display a table of BMSHV voltage values
            if (ImGui::BeginTable("BMSHVVOLTAGE", 12, ImGuiTableFlags_SizingFixedSame)) {
                ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 40.0f);  
                for (int i = 0; i < dataBase->bmsData.getNumCellHV(); i++) {
                    ImGui::TableNextColumn();                
                    ImGui::Text("%.2f", dataBase->bmsData.bmsHVVoltage[i]);
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(dataBase->bmsData.bmsHVVoltage[i]));
                }
                ImGui::EndTable();
            }
        }

        if (ImGui::CollapsingHeader("BMSLV")) {
            // Display BMSLV information
            ImGui::Text("AGE %.2f Km", dataBase->bmsData.getBMSLVAGE());
            ImGui::Text("BMSLVTEMPERATURE %.2f °C", dataBase->bmsData.getBMSLVTotalTemperature());
            ImGui::Text("BMSLVCURRENT %.2f A", dataBase->bmsData.getBMSLVCURRENT());
            ImGui::Text("BMSLVVOLTAGE %.2f V", dataBase->bmsData.getBMSLVTotalVoltage());
            ImGui::Text("BMSLVVOLTAGE CELLS: (V)");
            
            // Display a table of BMSLV voltage values
            if (ImGui::BeginTable("BMSLVVOLTAGE", 4, ImGuiTableFlags_SizingFixedSame)) {
                ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 40.0f);  
                for (int i = 0; i < dataBase->bmsData.getNumCellLV(); i++) {
                    ImGui::TableNextColumn();                
                    ImGui::Text("%.2f", dataBase->bmsData.bmsLVVoltage[i]);
                    ImGui::TableSetBgColor(ImGuiTableBgTarget_CellBg, setBgColor(dataBase->bmsData.bmsLVVoltage[i]));
                }
                ImGui::EndTable();
            }
        }

        ImGui::End();
    }
}