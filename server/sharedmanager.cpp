#include "sharedmanager.h"

//================================================================
//          Methods to manage shared user activites
//================================================================

SharedManager::SharedManager()
{
}

int SharedManager::loginHandler(std::string username){
    qDebug() << "Login request made";

//TODO this is a place holder
    if (username == "student") {
        qDebug() << "student";
        return 2;
    } else if (username == "contentmanager") {
        qDebug() << "CTM";
        return 3;
    } else if (username == "admin") {
        qDebug() << "admin";
        return 4;
    } else {
        qDebug() << "failed";
        return -1;
    }
}
