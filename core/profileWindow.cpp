#include <string>
#include "app.h"

using namespace std;

static char username[64] = "";
static char password[64] = "";
bool passwordMode = false;
bool firstTime = true;
vector<bool> maintainerSelection;
vector<bool> adminSelection;

void initializeSelection(int, int);
void clearSelection(int, int);

void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayShort))
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

void profile(DataBase* dataBase){
    if(ImGui::Begin("Profile", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(dataBase->user->permission == 0){
            ImGui::Text("You are not logged\nEnter your username and password to log in");
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
                        dataBase->setUser(username, password, 1);
                        dataBase->user->setupProfileWindow();
                        cout << "permesso user " << dataBase->user->permission << endl;
                    }
                    else{
                        cout << "maintainer non riconosciuto" << endl;
                    }
                } 
                for(int i = 0; i < dataBase->adminLogin.size(); i++){
                AdminUser* adminPtr = dataBase->adminLogin[i].get();
                    if(strcmp(username, adminPtr->username) == 0 && strcmp(password, adminPtr->password) == 0){
                        cout << "admin riconosciuto" << endl;
                        dataBase->setUser(username, password, 2);
                        dataBase->user->setupProfileWindow();
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
        }
        else{
            switch (dataBase->user->permission){
            case 1:
                ImGui::Text("You are logged as a Maintainer");
                break;
            case 2:
                ImGui::Text("You are logged as a Admin");
                break;
            default:
                break;
            }
            ImGui::Text("Click here to logout");
            if(ImGui::Button("LOGOUT")){
                dataBase->setUser("", "", 0);
                strcpy(username, "");
                strcpy(password, "");
                firstTime = true;
            }
            if(dataBase->user->permission == 2){
                if(ImGui::CollapsingHeader("Member Management")){
                    if(firstTime){
                        initializeSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                        firstTime = false;
                    }
                    HelpMarker("Hold CTRL and click to select multiple items.");
                    if(ImGui::TreeNode("Maintainer")){
                        for (int n = 0; n < dataBase->maintainerLogin.size(); n++){
                            char buf[32];
                            sprintf(buf, dataBase->maintainerLogin[n]->username);
                            if (ImGui::Selectable(buf, maintainerSelection[n])){
                                if (!ImGui::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                                    clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                maintainerSelection[n] = !maintainerSelection[n];
                            }
                        }
                        ImGui::TreePop();
                    }
                    if(ImGui::TreeNode("Admin")){
                        for (int n = 0; n < dataBase->adminLogin.size(); n++){
                            char buf[32];
                            sprintf(buf, dataBase->adminLogin[n]->username);
                            if (ImGui::Selectable(buf, adminSelection[n])){
                                if (!ImGui::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                                    clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                adminSelection[n] = !adminSelection[n];
                            }
                        }
                        ImGui::TreePop();
                    }
                }
            }
        }
        ImGui::End();
    }
}

void initializeSelection(int maintainerSize, int adminSize){
    for(int i = 0; i < maintainerSize; i++){
        maintainerSelection.push_back(false);
    }
    for(int i = 0; i < adminSize; i++){
        adminSelection.push_back(false);
    }
}

void clearSelection(int maintainerSize, int adminSize){
    for(int i = 0; i < maintainerSize; i++){
        maintainerSelection[i] = false;
    }
    for(int i = 0; i < adminSize; i++){
        adminSelection[i] = false;
    }
}