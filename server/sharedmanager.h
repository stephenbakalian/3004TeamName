#ifndef SHAREDMANAGER_H
#define SHAREDMANAGER_H

#include <string>
#include <QDebug>
#include <QString>
#include "database.h"

class SharedManager
{
public:
    SharedManager();
    int loginHandler(std::string username, DataBase* myDB);
};

#endif // SHAREDMANAGER_H
