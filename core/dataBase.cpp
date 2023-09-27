#include "dataBase.h"

using namespace std;
// Function to set a user in the database based on username, password, and permission level
void DataBase::setUser(string username, string password, int permission) {
    // Check if a user already exists and reset it if so
    if (user != nullptr) {
        user.reset(nullptr);
    }
    
    // Create a new user based on the provided permission level
    switch (permission) {
        case 0:
            user = make_unique<BasicUser>(username, password, 0);
            break;
        case 1:
            user = make_unique<MaintainerUser>(username, password, 1);
            break;
        case 2:
            user = make_unique<AdminUser>(username, password, 2);
            break;
        default:
            break;
    }
}

// Function to add a maintainer user to the database
void DataBase::addMaintainer(string usr, string psw) {
    // Create a new MaintainerUser object and add it to the maintainerLogin vector
    unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>(usr, psw, 1);
    maintainerLogin.push_back(move(usr1));
}

// Function to add an admin user to the database
void DataBase::addAdmin(string usr, string psw) {
    // Create a new AdminUser object and add it to the adminLogin vector
    unique_ptr<AdminUser> usr1 = make_unique<AdminUser>(usr, psw, 1);
    adminLogin.push_back(move(usr1));
}

// Function to remove user(s) from the database based on lists of booleans
void DataBase::removeUser(vector<bool> listM, vector<bool> listA) {
    vector<unique_ptr<MaintainerUser>> newMaintainerList;
    vector<unique_ptr<AdminUser>> newAdminList;

    // Iterate through the list of maintainers and add those that are not marked for removal to the new list
    for (int i = 0; i < listM.size(); i++) {
        if (!listM[i]) {
            newMaintainerList.push_back(move(maintainerLogin[i]));
        }
    }

    // Iterate through the list of admins and add those that are not marked for removal to the new list
    for (int i = 0; i < listA.size(); i++) {
        if (!listA[i]) {
            newAdminList.push_back(move(adminLogin[i]));
        }
    }

    // Assign the new vectors to the original vectors to remove the desired elements
    maintainerLogin = move(newMaintainerList);
    adminLogin = move(newAdminList);
}

// Function to add a track to the database
void DataBase::addTrack(string name, string path, int n) {
    // Create a TelemetryData object and add it to the telemetryData vector
    TelemetryData telemetry(name, path, n);
    telemetryData.push_back(telemetry);
}

// Function to remove track(s) from the database based on a list of booleans
void DataBase::removeTrack(vector<bool> tracklist) {
    for (int i = 0; i < tracklist.size(); i++) {
        if (tracklist[i]) {
            // Erase the track at the specified index from the telemetryData vector
            telemetryData.erase(telemetryData.begin() + i);
        }
    }
}