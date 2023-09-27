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
            unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>("pippo", "paperino", 1);
            maintainerLogin.push_back(move(usr1));
            unique_ptr<AdminUser> usr2 = make_unique<AdminUser>("minnie", "paperino", 2);
            adminLogin.push_back(move(usr2));
            unique_ptr<MaintainerUser> usr3 = make_unique<MaintainerUser>("tolopino", "paperino", 1);
            maintainerLogin.push_back(move(usr3));
            unique_ptr<AdminUser> usr4 = make_unique<AdminUser>("pluto", "paperino", 2);
            adminLogin.push_back(move(usr4));
            // unique_ptr<TelemetryData> telemetry = make_unique<TelemetryData>("Hockenheimring", "Hockenheim2012.jpg", 5);
            TelemetryData telemetry("Hockenheimring", "../data/Hockenheim2012.jpg", 5);
            telemetryData.push_back(telemetry);
            setUser("", "", 0);
        }
        
        void setUser(char*, char*, int);
        void addMaintainer(char*, char*);
        void addAdmin(char*, char*);
        void removeUser(vector<bool>, vector<bool>);
        void addTrack(char*, char*, int);
        void removeTrack(vector<bool>);
};