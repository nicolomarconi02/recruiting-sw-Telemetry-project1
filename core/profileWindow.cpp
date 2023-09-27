#include <string>
#include "app.h"

using namespace std;

static char username[64] = "";
static char password[64] = "";
static char newusername[64] = "";
static char newpassword[64] = "";
bool passwordMode = false;
bool userFound = false;
bool mostraTestoLogin = false;
bool mostraTestoAdd = false;
static int e = 1;
int sizeMaintainer = 0;
int sizeAdmin = 0;


vector<bool> maintainerSelection;
vector<bool> adminSelection;

void initializeSelection(int, int);
void clearSelection(int, int);
bool checkUser(DataBase*,string);

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
                for(int i = 0; i < dataBase->maintainerLogin.size() && !userFound; i++){
                    MaintainerUser* maintainerPtr = dataBase->maintainerLogin[i].get();
                    if(strcmp(username, maintainerPtr->username.c_str()) == 0 && strcmp(password, maintainerPtr->password.c_str()) == 0){
                        cout << "maintainer riconosciuto" << endl;
                        dataBase->setUser(username, password, 1);
                        dataBase->user->setupProfileWindow();
                        cout << "permesso user " << dataBase->user->permission << endl;
                        userFound = true;
                    }
                    else{
                        cout << "maintainer non riconosciuto" << endl;
                    }
                } 
                for(int i = 0; i < dataBase->adminLogin.size() && !userFound; i++){
                    AdminUser* adminPtr = dataBase->adminLogin[i].get();
                    if(strcmp(username, adminPtr->username.c_str()) == 0 && strcmp(password, adminPtr->password.c_str()) == 0){
                        cout << "admin riconosciuto" << endl;
                        dataBase->setUser(username, password, 2);
                        dataBase->user->setupProfileWindow();
                        userFound = true;
                    }
                    else{
                        cout << "admin non riconosciuto" << endl;
                    }
                } 
                if(!userFound){
                    mostraTestoLogin = true;
                }
            }
            ImGui::SameLine();
            if(ImGui::Button("clear")){
                strcpy(username, "");
                strcpy(password, "");
                mostraTestoLogin = false;
                userFound = false;
            }
            if(mostraTestoLogin){
                ImGui::Text("Non esiste nessun user con queste credenziali");
            }
        }
        else{
            switch (dataBase->user->permission){
            case 1:
                ImGui::Text("%s\nYou are logged as a Maintainer", dataBase->user->username.c_str());
                break;
            case 2:
                ImGui::Text("%s\nYou are logged as a Admin", dataBase->user->username.c_str());
                break;
            default:
                break;
            }
            ImGui::Text("Click here to logout");
            if(ImGui::Button("LOGOUT")){
                dataBase->setUser("", "", 0);
                strcpy(username, "");
                strcpy(password, "");
                mostraTestoLogin = false;
                userFound = false;
            }
            if(dataBase->user->permission == 2){
                if(ImGui::CollapsingHeader("Member Management")){
                    if(sizeAdmin != dataBase->adminLogin.size() || sizeMaintainer != dataBase->maintainerLogin.size()){
                        sizeAdmin = dataBase->adminLogin.size();
                        sizeMaintainer = dataBase->maintainerLogin.size();
                        initializeSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                    }
                    HelpMarker("Hold CTRL and click to select multiple items.");
                    if(ImGui::TreeNode("Maintainer")){
                        if(ImGui::BeginListBox("")){
                            for (int n = 0; n < dataBase->maintainerLogin.size(); n++){
                                char buf[32];
                                sprintf(buf, dataBase->maintainerLogin[n]->username.c_str());
                                if (ImGui::Selectable(buf, maintainerSelection[n])){
                                    if (!ImGui::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                                        clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                    maintainerSelection[n] = !maintainerSelection[n];
                                }
                            }
                            ImGui::EndListBox();
                        }
                        ImGui::TreePop();
                    }
                    if(ImGui::TreeNode("Admin")){
                        if(ImGui::BeginListBox("")){
                            for (int n = 0; n < dataBase->adminLogin.size(); n++){
                                char buf[32];
                                sprintf(buf, dataBase->adminLogin[n]->username.c_str());
                                if (ImGui::Selectable(buf, adminSelection[n])){
                                    if (!ImGui::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                                        clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                    adminSelection[n] = !adminSelection[n];
                                }
                            }
                            ImGui::EndListBox();
                        }
                        ImGui::TreePop();
                    }
                    ImGuiInputTextFlags flags = passwordMode ? 0 : ImGuiInputTextFlags_Password;
                    ImGui::InputText("username", newusername, 64);
                    ImGui::InputText("password", newpassword, 64, flags);
                    ImGui::SameLine();
                    ImGui::Checkbox("View password", &passwordMode);
                    ImGui::RadioButton("Maintainer", &e, 1);
                    if(ImGui::IsItemClicked()){
                        e = 1;
                    }
                    ImGui::SameLine();
                    ImGui::RadioButton("Admin", &e, 2);
                    if(ImGui::IsItemClicked()){
                        e = 2;
                    }
                    if(mostraTestoAdd){
                        ImGui::Text("Esiste gia' un utente con quel nome");
                    }

                    if(ImGui::Button("Add User")){
                        if(!checkUser(dataBase, newusername)){
                            if(e == 1){
                                dataBase->addMaintainer(newusername, newpassword);
                            }
                            else{
                                dataBase->addAdmin(newusername, newpassword);
                            }
                            mostraTestoAdd = false;
                        }
                        else{
                            mostraTestoAdd = true;
                        }
                        
                    }
                    if(ImGui::Button("Remove Selected User")){
                        dataBase->removeUser(maintainerSelection, adminSelection);
                    }
                }
            }
        }
        ImGui::End();
    }
}

void initializeSelection(int maintainerSize, int adminSize){
    maintainerSelection.clear();
    adminSelection.clear();

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

bool checkUser(DataBase* db,string name){
    bool uguale = false;
    for(int i = 0; i < db->maintainerLogin.size() && !uguale; i++){
        if(db->maintainerLogin[i]->username == name){
            uguale = true;
        }
    }
    for(int i = 0; i < db->adminLogin.size() && !uguale; i++){
        if(db->adminLogin[i]->username == name){
            uguale = true;
        }
    }
    return uguale;
}