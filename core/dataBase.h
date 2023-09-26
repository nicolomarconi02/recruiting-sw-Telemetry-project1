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

using namespace std;

class DataBase{
    public:
        vector<unique_ptr<MaintainerUser>> maintainerLogin;
        vector<unique_ptr<AdminUser>> adminLogin;
        unique_ptr<BasicUser> user = nullptr;
        TelemetryData telemetryData;
        BMSData bmsData;
        TyreData tyreData;
        MotorData motorData;

        DataBase(){
            unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>("pippo", "paperino", 1);
            maintainerLogin.push_back(move(usr1));
            unique_ptr<AdminUser> usr2 = make_unique<AdminUser>("topolino", "paperino", 2);
            adminLogin.push_back(move(usr2));
            unique_ptr<MaintainerUser> usr3 = make_unique<MaintainerUser>("tolopino", "paperino", 1);
            maintainerLogin.push_back(move(usr3));
            unique_ptr<AdminUser> usr4 = make_unique<AdminUser>("pluto", "paperino", 2);
            adminLogin.push_back(move(usr4));
            setUser("", "", 0);
        }
        void setUser(char*, char*, int);

};