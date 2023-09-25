#include <string>
#include "app.h"

using namespace std;

static char username[64] = "";
static char password[64] = "";
bool passwordMode = false;

void profile(DataBase* dataBase){
    if(ImGui::Begin("Profile", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGuiInputTextFlags flags = passwordMode ? 0 : ImGuiInputTextFlags_Password;
        ImGui::InputText("username", username, 64);
        ImGui::InputText("password", password, 64, flags);
        ImGui::SameLine();
        ImGui::Checkbox("View password", &passwordMode);
        if(ImGui::Button("check")){
            for(int i = 0; i < dataBase->maintainerLogin.size(); i++){
            MaintainerUser* maintainerPtr = dataBase->maintainerLogin[i].get();
                if(strcmp(username, maintainerPtr->username) == 0 && strcmp(password, maintainerPtr->password) == 0){
                    cout << "maintainer riconosciuto" << endl;  
                }
                else{
                    cout << "maintainer non riconosciuto" << endl;
                }
            } 
            for(int i = 0; i < dataBase->adminLogin.size(); i++){
            AdminUser* adminPtr = dataBase->adminLogin[i].get();
                if(strcmp(username, adminPtr->username) == 0 && strcmp(password, adminPtr->password) == 0){
                    cout << "admin riconosciuto" << endl;
                    
                }
                else{
                    cout << "admin non riconosciuto" << endl;
                }
            } 
        }
        ImGui::SameLine();
        if(ImGui::Button("clear")){
            strcpy(username, "");
            strcpy(password, "");
        }
        ImGui::End();
    }
}