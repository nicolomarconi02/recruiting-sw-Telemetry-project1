#include "dataBase.h"

using namespace std;

void DataBase::setUser(char* username, char* password, int permission){
    if(user != nullptr){
        user.reset(nullptr);
    }
    switch (permission)
    {
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
    cout << "print username: " << user->username << " password: " << user->password << endl;
}

void DataBase::addMaintainer(char* usr, char* psw){
    unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>(usr, psw, 1);
    maintainerLogin.push_back(move(usr1));
}   
        
        
void DataBase::addAdmin(char* usr, char* psw){
    unique_ptr<AdminUser> usr1 = make_unique<AdminUser>(usr, psw, 1);
    adminLogin.push_back(move(usr1));
}

void DataBase::removeUser(vector<bool> listM, vector<bool> listA){
    vector<unique_ptr<MaintainerUser>> newMaintainerList;
    vector<unique_ptr<AdminUser>> newAdminList;

    for (int i = 0; i < listM.size(); i++) {
        if (!listM[i]) {
            newMaintainerList.push_back(move(maintainerLogin[i]));
        }
    }

    for (int i = 0; i < listA.size(); i++) {
        if (!listA[i]) {
            newAdminList.push_back(move(adminLogin[i]));
        }
    }

    // Assegna i nuovi vettori ai vettori originali per rimuovere gli elementi desiderati
    maintainerLogin = move(newMaintainerList);
    adminLogin = move(newAdminList);
}

void DataBase::addTrack(char* name, char* path, int n){
    TelemetryData telemetry(name, path, n);
    telemetryData.push_back(telemetry);
}