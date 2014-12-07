#include "studentmanager.h"

//================================================================
//          Methods to manage the student user
//================================================================


StudentManager::StudentManager()
{
}

int StudentManager::addToPreviouslyPurchasedItems(std::string studentName, std::string itemKeys[]) {
    //TODO

    return -5;
}

int StudentManager::addToCart(std::string studentName, std::string itemKeys[]) {
    //TODO

    return -5;
}

QList<Item> StudentManager::viewPurchasedItems(std::string studentName) {
    //TODO
    Item *temp1 = new Item;
    temp1->setTitle("waffles");
    Item *temp2 = new Item;
    temp2->setTitle("to many cooks");

    QList<Item> books;
    books.push_back(*temp1);
    books.push_back(*temp2);
    return books;

}
