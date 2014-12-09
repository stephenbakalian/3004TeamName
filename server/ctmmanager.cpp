#include "ctmmanager.h"
#include "database.h"

//================================================================
//          Methods to manage the CTM user
//================================================================

CTMManager::CTMManager()
{
}

int CTMManager::additem(Item item, DataBase* myDB){

    //myDB->create
    return -5;
}

QList<Item> CTMManager::getAllItems(DataBase* myDB){

    QList<Item> books;
    QList<Item> item;
    QList<Item>::iterator i;

    item = myDB->getAllItems();

    for (i = item.begin(); i != item.end(); ++i){
        books.push_back(*i);
    }

    return books;
}
