#ifndef CTMMANAGER_H
#define CTMMANAGER_H

#include <QList>
#include "item.h"
#include "database.h"
#include "ctmmanager.h"

class CTMManager
{
public:
    CTMManager();
    int additem(Item item, DataBase *myDB);
    QList<Item> getAllItems(DataBase *myDB);
};

#endif // CTMMANAGER_H
