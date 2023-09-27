#include <string>
#include "app.h"

using namespace std;

// Define static variables and flags for user interface state
static char username[64] = "";
static char password[64] = "";
static char newusername[64] = "";
static char newpassword[64] = "";
bool passwordMode = false;
bool userFound = false;
bool mostraTestoLogin = false;
bool mostraTestoAdd = false;
static int e = 1; // RadioButton selection
int sizeMaintainer = 0;
int sizeAdmin = 0;

string messageTextLogin = "";
string messageTextAdd = "";

vector<bool> maintainerSelection;
vector<bool> adminSelection;

// Function to initialize selection flags
void initializeSelection(int, int);
void clearSelection(int, int);
bool checkUser(DataBase*, string);

// HelpMarker function to display tooltips
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

void profile(DataBase* dataBase) {
    // Begin an ImGui window with certain settings
    if (ImGui::Begin("Profile", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        if (dataBase->user->permission == 0) {
            // Display login form for users with no permission
            ImGui::Text("You are not logged\nEnter your username and password to log in");

            // Define flags for password input field
            ImGuiInputTextFlags flags = passwordMode ? 0 : ImGuiInputTextFlags_Password;

            // Input fields for username and password
            ImGui::InputText("username", username, 64);
            ImGui::InputText("password", password, 64, flags);

            // Checkbox to toggle password visibility
            ImGui::SameLine();
            ImGui::Checkbox("View password", &passwordMode);

            // "Check" button for attempting login
            if (ImGui::Button("check")) {
                // Attempt to find the user in the database based on input credentials
                // Check Maintainer users
                for (int i = 0; i < dataBase->maintainerLogin.size() && !userFound; i++) {
                    MaintainerUser* maintainerPtr = dataBase->maintainerLogin[i].get();
                    if (strcmp(username, maintainerPtr->username.c_str()) == 0 &&
                        strcmp(password, maintainerPtr->password.c_str()) == 0) {
                        // Set the logged-in user, update the user's profile window, and set userFound to true
                        dataBase->setUser(username, password, 1);
                        dataBase->user->setupProfileWindow();
                        userFound = true;
                    } else {
                        messageTextLogin = "maintainer not found";
                    }
                }
                // Check Admin users
                for (int i = 0; i < dataBase->adminLogin.size() && !userFound; i++) {
                    AdminUser* adminPtr = dataBase->adminLogin[i].get();
                    if (strcmp(username, adminPtr->username.c_str()) == 0 &&
                        strcmp(password, adminPtr->password.c_str()) == 0) {
                        // Set the logged-in user, update the user's profile window, and set userFound to true
                        dataBase->setUser(username, password, 2);
                        dataBase->user->setupProfileWindow();
                        userFound = true;
                    } else {
                        messageTextLogin = "admin not found";
                    }
                }
                // If no user found, display an error message
                if (!userFound) {
                    mostraTestoLogin = true;
                    messageTextLogin = "no users match the credentials";
                }
            }

            // "Clear" button to reset input fields and messages
            ImGui::SameLine();
            if (ImGui::Button("clear")) {
                strcpy(username, "");
                strcpy(password, "");
                mostraTestoLogin = false;
                userFound = false;
            }

            // Display error message if mostraTestoLogin is true
            if (mostraTestoLogin) {
                ImGui::Text(messageTextLogin.c_str());
            }
        } else {
            // Display user profile information for logged-in users
            switch (dataBase->user->permission) {
            case 1:
                ImGui::Text("%s\nYou are logged as a Maintainer", dataBase->user->username.c_str());
                break;
            case 2:
                ImGui::Text("%s\nYou are logged as an Admin", dataBase->user->username.c_str());
                break;
            default:
                break;
            }

            // Button to log out the user
            ImGui::Text("Click here to logout");
            if (ImGui::Button("LOGOUT")) {
                dataBase->setUser("", "", 0);
                strcpy(username, "");
                strcpy(password, "");
                mostraTestoLogin = false;
                userFound = false;
                dataBase->user->setupProfileWindow();
            }

            // Admin-specific functionality
            if (dataBase->user->permission == 2) {
                // Section for Member Management
                if (ImGui::CollapsingHeader("Member Management")) {
                    if (sizeAdmin != dataBase->adminLogin.size() ||
                        sizeMaintainer != dataBase->maintainerLogin.size()) {
                        sizeAdmin = dataBase->adminLogin.size();
                        sizeMaintainer = dataBase->maintainerLogin.size();
                        initializeSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                    }

                    // Display help marker tooltip
                    HelpMarker("Hold CTRL and click to select multiple items.");

                    // Display lists of Maintainers and Admins with checkboxes for selection
                    if (ImGui::TreeNode("Maintainer")) {
                        if (ImGui::BeginListBox("")) {
                            for (int n = 0; n < dataBase->maintainerLogin.size(); n++) {
                                char buf[32];
                                sprintf(buf, dataBase->maintainerLogin[n]->username.c_str());
                                if (ImGui::Selectable(buf, maintainerSelection[n])) {
                                    clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                    maintainerSelection[n] = !maintainerSelection[n];
                                }
                            }
                            ImGui::EndListBox();
                        }
                        ImGui::TreePop();
                    }

                    if (ImGui::TreeNode("Admin")) {
                        if (ImGui::BeginListBox("")) {
                            for (int n = 0; n < dataBase->adminLogin.size(); n++) {
                                char buf[32];
                                sprintf(buf, dataBase->adminLogin[n]->username.c_str());
                                if (ImGui::Selectable(buf, adminSelection[n])) {
                                    clearSelection(dataBase->maintainerLogin.size(), dataBase->adminLogin.size());
                                    adminSelection[n] = !adminSelection[n];
                                }
                            }
                            ImGui::EndListBox();
                        }
                        ImGui::TreePop();
                    }

                    // Input fields for adding a new user
                    ImGuiInputTextFlags flags = passwordMode ? 0 : ImGuiInputTextFlags_Password;
                    ImGui::InputText("username", newusername, 64);
                    ImGui::InputText("password", newpassword, 64, flags);
                    ImGui::SameLine();
                    ImGui::Checkbox("View password", &passwordMode);
                    ImGui::RadioButton("Maintainer", &e, 1);
                    if (ImGui::IsItemClicked()) {
                        e = 1;
                    }
                    ImGui::SameLine();
                    ImGui::RadioButton("Admin", &e, 2);
                    if (ImGui::IsItemClicked()) {
                        e = 2;
                    }

                    // Display error message if mostraTestoAdd is true
                    if (mostraTestoAdd) {
                        ImGui::Text(messageTextAdd.c_str());
                    }

                    // Button to add a new user
                    if (ImGui::Button("Add User")) {
                        if (strcmp(newusername, "") != 0 && strcmp(newpassword, "") != 0) {
                            mostraTestoAdd = false;
                            if (!checkUser(dataBase, newusername)) {
                                if (e == 1) {
                                    dataBase->addMaintainer(newusername, newpassword);
                                } else {
                                    dataBase->addAdmin(newusername, newpassword);
                                }
                                mostraTestoAdd = false;
                            } else {
                                mostraTestoAdd = true;
                                messageTextAdd = "A user with those credentials already exists";
                            }
                        } else {
                            mostraTestoAdd = true;
                            messageTextAdd = "You have to insert a username and a password";
                        }
                    }

                    // Button to remove selected users
                    if (ImGui::Button("Remove Selected User")) {
                        dataBase->removeUser(maintainerSelection, adminSelection);
                    }
                }
            }
        }
        // End ImGui window
        ImGui::End();
    }
}

void initializeSelection(int maintainerSize, int adminSize) {
    // Clear and initialize the selection vectors for Maintainers and Admins

    // Clear any previous selections
    maintainerSelection.clear();
    adminSelection.clear();

    // Initialize Maintainer selections
    for (int i = 0; i < maintainerSize; i++) {
        maintainerSelection.push_back(false);
    }

    // Initialize Admin selections
    for (int i = 0; i < adminSize; i++) {
        adminSelection.push_back(false);
    }
}

void clearSelection(int maintainerSize, int adminSize) {
    // Clear the selection for Maintainers and Admins

    // Clear Maintainer selections
    for (int i = 0; i < maintainerSize; i++) {
        maintainerSelection[i] = false;
    }

    // Clear Admin selections
    for (int i = 0; i < adminSize; i++) {
        adminSelection[i] = false;
    }
}

bool checkUser(DataBase* db, string name) {
    // Check if a user with the given username exists in the database

    bool uguale = false;

    // Check Maintainer usernames
    for (int i = 0; i < db->maintainerLogin.size() && !uguale; i++) {
        if (db->maintainerLogin[i]->username == name) {
            uguale = true;
        }
    }

    // Check Admin usernames
    for (int i = 0; i < db->adminLogin.size() && !uguale; i++) {
        if (db->adminLogin[i]->username == name) {
            uguale = true;
        }
    }

    return uguale;
}