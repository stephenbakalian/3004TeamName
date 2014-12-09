#ifndef CTMMANAGER_H
#define CTMMANAGER_H

#include <QList>
#include "item.h"

class CTMManager
{
public:
    CTMManager();
    int additem(Item item);
    QList<Item> getAllItems();
};

#endif // CTMMANAGER_H
