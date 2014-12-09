#include "ctmmanager.h"
#include "database.h"
#include "item.h"

//================================================================
//          Methods to manage the CTM user
//================================================================

CTMManager::CTMManager()
{
}

int CTMManager::additem(Item item, DataBase* myDB){

    int successful = -1;

    /*if (myDB->getItem(QString::fromStdString(item.getISBN())) != NULL){

        successful = myDB->updateItem(QString::fromStdString(item.getISBN()),
                                      QString::fromStdString(item.getPrice()),
                                      QString::fromStdString(item.getTitle()),
                                      QString::fromStdString(item.getAuthor()),
                                      QString::fromStdString(item.getDescription()),
                                      QString::fromStdString(item.getLength()),
                                      QString::fromStdString(item.getType()),
                                      QString::fromStdString(item.getCourse()));

    }*/

    successful = myDB->createItem(QString::fromStdString(item.getISBN()),
                                  QString::fromStdString(item.getPrice()),
                                  QString::fromStdString(item.getTitle()),
                                  QString::fromStdString(item.getAuthor()),
                                  QString::fromStdString(item.getDescription()),
                                  QString::fromStdString(item.getLength()),
                                  QString::fromStdString(item.getType()),
                                  QString::fromStdString(item.getCourse()));

    qDebug() << QString::fromStdString(item.getISBN());
    qDebug() << QString::fromStdString(item.getPrice());
    qDebug() << QString::fromStdString(item.getTitle());
    qDebug() << QString::fromStdString(item.getAuthor());
    qDebug() << QString::fromStdString(item.getDescription());
    qDebug() << QString::fromStdString(item.getLength());
    qDebug() << QString::fromStdString(item.getType());
    qDebug() << QString::fromStdString(item.getCourse());

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
