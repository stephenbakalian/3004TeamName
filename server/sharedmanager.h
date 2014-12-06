#ifndef SHAREDMANAGER_H
#define SHAREDMANAGER_H

#include <string>
#include <QDebug>
#include <QString>

class SharedManager
{
public:
    SharedManager();
    int loginHandler(std::string username);
};

#endif // SHAREDMANAGER_H
