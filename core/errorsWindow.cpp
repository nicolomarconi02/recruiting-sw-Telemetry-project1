#include "app.h"

void errors(DataBase* dataBase){
    if(ImGui::Begin("Errors", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("ELECTRONIC")){
            if(ImGui::BeginListBox("")){
                for(int i = 0; i < dataBase->bmsData.error.electronicErrorList.size(); i++){
                    ImGui::Text(dataBase->bmsData.error.electronicErrorList[i]);
                }
                ImGui::EndListBox();
            }
        }
        if(ImGui::CollapsingHeader("MOTOR")){
            
        }
        if(ImGui::CollapsingHeader("TYRE")){
            
        }
        ImGui::End();
    }   
}