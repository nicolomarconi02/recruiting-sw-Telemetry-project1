#include "app.h"

// This function is responsible for rendering error messages related to different components.
void errors(DataBase* dataBase){
    if(ImGui::Begin("Errors", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        // Display errors related to the ELECTRONIC component if available.
        if(ImGui::CollapsingHeader("ELECTRONIC")){
            for(int i = 0; i < dataBase->bmsData.error.electronicErrorList.size(); i++){
                ImGui::Text(dataBase->bmsData.error.electronicErrorList[i].c_str());
            }
        }
        
        // Display errors related to the MOTOR component if available.
        if(ImGui::CollapsingHeader("MOTOR")){
            for(int i = 0; i < dataBase->motorData.error.motorErrorList.size(); i++){
                ImGui::Text(dataBase->motorData.error.motorErrorList[i].c_str());
            }
        }
        
        // Display errors related to the TYRE component if available.
        if(ImGui::CollapsingHeader("TYRE")){
            for(int i = 0; i < dataBase->tyreData.error.tyreErrorList.size(); i++){
                ImGui::Text(dataBase->tyreData.error.tyreErrorList[i].c_str());
            }
        }
        
        ImGui::End(); // End the ImGui window.
    }   
}