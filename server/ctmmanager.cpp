#include "ctmmanager.h"
#include "database.h"

//================================================================
//          Methods to manage the CTM user
//================================================================

CTMManager::CTMManager()
{
}

int CTMManager::additem(Item item, DataBase* myDB){

    int successful = -5;

    successful = myDB->createItem(QString::fromStdString(item.getISBN()),
                                  QString::fromStdString(item.getPrice()),
                                  QString::fromStdString(item.getTitle()),
                                  QString::fromStdString(item.getAuthor()),
                                  QString::fromStdString(item.getDescription()),
                                  QString::fromStdString(item.getLength()),
                                  QString::fromStdString(item.getType()),
                                  QString::fromStdString(item.getCourse()));

    return successful;
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
