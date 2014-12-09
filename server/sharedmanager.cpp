#include "sharedmanager.h"
#include "database.h"

//================================================================
//          Methods to manage shared user activites
//================================================================

SharedManager::SharedManager()
{
}

int SharedManager::loginHandler(std::string username, DataBase* myDB){
    //qDebug() << "Login request made";
    qDebug() << myDB->getUser(QString::fromStdString(username));
    return myDB->getUser(QString::fromStdString(username));

}
