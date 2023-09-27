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

class DataBase {
public:
    // Vectors to store user data
    vector<unique_ptr<MaintainerUser>> maintainerLogin;
    vector<unique_ptr<AdminUser>> adminLogin;
    
    // A user object with polymorphic behavior
    unique_ptr<BasicUser> user = nullptr;
    
    // Vector to store telemetry data
    vector<TelemetryData> telemetryData;
    
    // Objects to store various data types
    BMSData bmsData;
    TyreData tyreData;
    MotorData motorData;

    // Constructor to initialize some sample data
    DataBase() {
        // Add sample maintainers and admins to the login vectors
        unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>("maintainer", "maintainer", 1);
        maintainerLogin.push_back(move(usr1));
        unique_ptr<AdminUser> usr2 = make_unique<AdminUser>("admin", "admin", 2);
        adminLogin.push_back(move(usr2));
        unique_ptr<MaintainerUser> usr3 = make_unique<MaintainerUser>("tolopino", "paperino", 1);
        maintainerLogin.push_back(move(usr3));
        unique_ptr<AdminUser> usr4 = make_unique<AdminUser>("pluto", "paperino", 2);
        adminLogin.push_back(move(usr4));
        
        // Add a sample telemetry track
        TelemetryData telemetry("Hockenheimring", "Hockenheim2012.jpg", 5);
        telemetryData.push_back(telemetry);
        
        // Set an initial user (empty user) with setUser
        setUser("", "", 0);
    }
    
    // Function to set a user in the database based on username, password, and permission level
    void setUser(string, string, int);
    
    // Function to add a maintainer user to the database
    void addMaintainer(string, string);
    
    // Function to add an admin user to the database
    void addAdmin(string, string);
    
    // Function to remove user(s) from the database based on lists of booleans
    void removeUser(vector<bool>, vector<bool>);
    
    // Function to add a telemetry track to the database
    void addTrack(string, string, int);
    
    // Function to remove track(s) from the database based on a list of booleans
    void removeTrack(vector<bool>);
};