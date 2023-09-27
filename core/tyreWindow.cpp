#include "app.h"
#include "image.h"

using namespace std;

void displayGraphic(DataBase*, int, ImVec2);
void printInfo(DataBase*, int, ImVec2);
int setIndex(int);

void tyre(DataBase* dataBase){
    if(ImGui::Begin("Tyres", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::BeginTable("BMSHVVOLTAGE", 4)){
            ImVec2 progressBarSize(20.0f,100.0f);
            for(int i = 0; i < 8; i++){
                ImGui::TableNextColumn();                
                if(i == 0 || i == 3 || i == 4 || i == 7){
                    printInfo(dataBase, setIndex(i), progressBarSize);
                }
                else{
                    displayGraphic(dataBase, setIndex(i), progressBarSize);
                }
            }
            ImGui::EndTable();
        }
        ImGui::End();
    }
}

void displayGraphic(DataBase* dataBase, int index, ImVec2 progressBarSize){
    ImGui::GetWindowDrawList()->AddRectFilled(
        ImGui::GetCursorScreenPos(),
        ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x, ImGui::GetCursorScreenPos().y + progressBarSize.y),
        IM_COL32(255, 255, 255, 255), // Color of the progress bar (white in this case)
        0.0f,                     // No rounding
        0                            // No flags
    );
    ImGui::GetWindowDrawList()->AddRectFilled(
        ImVec2(ImGui::GetCursorScreenPos().x + 2, ImGui::GetCursorScreenPos().y + 2),
        ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x - 2, ImGui::GetCursorScreenPos().y + progressBarSize.y * (1.0f - dataBase->tyreData.tyresState[index]) - 2),
        IM_COL32(255, 0, 0, 255), // Color of the progress bar (red in this case)
        0.0f,                     // No rounding
        0                            // No flags
    );
}

void printInfo(DataBase* dataBase, int index, ImVec2 progressBarSize){
    switch (index){
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
            ImGui::Text("ERROR IN SWITCH");
            break;
    }
    ImGui::Text("Age: %.2f Km", dataBase->tyreData.getTyreAge());
    ImGui::Text("State: %.2f%%", dataBase->tyreData.tyresState[index] * 100.0f);
    ImGui::Text("Temperature: %.2f °C", dataBase->tyreData.tyresTemperature[index]);
    if(index == 1)
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + progressBarSize.y);

}

int setIndex(int i){
    int index = 0;
    switch (i){
        case 0:
        case 1:
            index = 0;
            break;
        case 2:
        case 3:
            index = 1;
            break;
        case 4:
        case 5:
            index = 2;
            break;
        case 6:
        case 7:
            index = 3;
            break;
        default:
            cout << "Index not available" << endl;
            break;
    }
    return index;
}