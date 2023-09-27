#include "app.h"

void errors(DataBase* dataBase){
    if(ImGui::Begin("Errors", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("ELECTRONIC")){
            for(int i = 0; i < dataBase->bmsData.error.electronicErrorList.size(); i++){
                ImGui::Text(dataBase->bmsData.error.electronicErrorList[i].c_str());
            }
        }
        if(ImGui::CollapsingHeader("MOTOR")){
            for(int i = 0; i < dataBase->motorData.error.motorErrorList.size(); i++){
                ImGui::Text(dataBase->motorData.error.motorErrorList[i].c_str());
            }
        }
        if(ImGui::CollapsingHeader("TYRE")){
            for(int i = 0; i < dataBase->tyreData.error.tyreErrorList.size(); i++){
                ImGui::Text(dataBase->tyreData.error.tyreErrorList[i].c_str());
            }
        }
        ImGui::End();
    }   
}