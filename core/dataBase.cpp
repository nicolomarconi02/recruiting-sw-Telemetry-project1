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