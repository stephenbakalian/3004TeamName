#include "ctmmanager.h"

//================================================================
//          Methods to manage the CTM user
//================================================================

CTMManager::CTMManager()
{
}

int CTMManager::additem(Item item){
    //TODO
    return -5;
}

QList<Item> CTMManager::getAllItems(){
    Item *temp1 = new Item;
    temp1->setTitle("waffles");
    Item *temp2 = new Item;
    temp2->setTitle("to many cooks");
    Item *temp3 = new Item();
    Item *temp4 = new Item();
    temp3->setTitle("test");
    temp4->setTitle("Hai");

    QList<Item> books;
    books.push_back(*temp1);
    books.push_back(*temp2);
    books.push_back(*temp3);
    books.push_back(*temp4);    //TODO
    //return -5;
    return books;
}
