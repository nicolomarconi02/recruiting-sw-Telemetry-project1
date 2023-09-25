#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "basicUser.h"
#include "maintainerUser.h"
#include "adminUser.h"

using namespace std;

class DataBase{
    public:
        vector<unique_ptr<MaintainerUser>> maintainerLogin;
        vector<unique_ptr<AdminUser>> adminLogin;
        // BasicUser* user = NULL;
        DataBase(){
            unique_ptr<MaintainerUser> usr1 = make_unique<MaintainerUser>("pippo", "paperino", 1);
            maintainerLogin.push_back(move(usr1));
            // cout << "maintainer " << maintainerLogin[0].username << maintainerLogin[0].password << endl;
            // fflush(stdout);
            unique_ptr<AdminUser> usr2 = make_unique<AdminUser>("pluto", "paperino", 2);
            adminLogin.push_back(move(usr2));
            // AdminUser usr2("pluto", "paperino", 2);
            // adminLogin.push_back(usr2);
            // cout << "adminLogin " << adminLogin[0].username << adminLogin[0].password << endl;
            // fflush(stdout);
        }
        // void setUser(int, char*, char*);

};