#include "dataBase.h"

using namespace std;

void DataBase::setUser(int permission, char* username, char* password){
    switch (permission)
    {
        case 0:
            if(user != NULL){
                delete user;
            }
            user = new BasicUser(username, password, 0);
            break;
        case 1:
            if(user != NULL){
                delete user;
            }
            user = new MaintainerUser(username, password, 1);
            break;
        case 2:
            if(user != NULL){
                delete user;
            }
            user = new AdminUser(username, password, 2);
            break;
        default:
            break;
    }
}