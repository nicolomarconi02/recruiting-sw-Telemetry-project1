#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "basicUser.h"
#include "maintainerUser.h"
#include "adminUser.h"
#include "telemetry.h"
#include "bms.h"
#include "tyre.h"
#include "motor.h"
#include "track.h"

using namespace std;

class DataBase{
    public:
        vector<unique_ptr<MaintainerUser>> maintainerLogin;
        vector<unique_ptr<AdminUser>> adminLogin;
        unique_ptr<BasicUser> user = nullptr;
        // vector<unique_ptr<TelemetryData>> telemetryData;
        vector<TelemetryData> telemetryData;
        BMSData bmsData;
        TyreData tyreData;
        MotorData motorData;

        DataBase(){
            unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>("maintainer", "maintainer", 1);
            maintainerLogin.push_back(move(usr1));
            unique_ptr<AdminUser> usr2 = make_unique<AdminUser>("admin", "admin", 2);
            adminLogin.push_back(move(usr2));
            unique_ptr<MaintainerUser> usr3 = make_unique<MaintainerUser>("tolopino", "paperino", 1);
            maintainerLogin.push_back(move(usr3));
            unique_ptr<AdminUser> usr4 = make_unique<AdminUser>("pluto", "paperino", 2);
            adminLogin.push_back(move(usr4));
            TelemetryData telemetry("Hockenheimring", "Hockenheim2012.jpg", 5);
            telemetryData.push_back(telemetry);
            setUser("", "", 0);
        }
        
        void setUser(string, string, int);
        void addMaintainer(string, string);
        void addAdmin(string, string);
        void removeUser(vector<bool>, vector<bool>);
        void addTrack(string, string, int);
        void removeTrack(vector<bool>);
};