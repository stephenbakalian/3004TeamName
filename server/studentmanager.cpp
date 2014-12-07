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
    Item *temp3 = new Item();
    Item *temp4 = new Item();
    temp3->setTitle("test");
    temp4->setTitle("Hai");

    QList<Item> books;
    books.push_back(*temp1);
    books.push_back(*temp2);
    books.push_back(*temp3);
    books.push_back(*temp4);
    return books;

}

QList<Item> StudentManager::viewCart(std::string studentName) {
    Item *temp1 = new Item();
    Item *temp2 = new Item();
    Item *temp3 = new Item();
    Item *temp4 = new Item();
    Item *temp5 = new Item();
    Item *temp6 = new Item();
    temp1->setTitle("HOW TO WIN at chess");
    temp2->setTitle("Batman beyond");
    temp3->setTitle("waffles");
    temp4->setTitle("Hai");
    temp5->setTitle("too many cooks");
    temp6->setTitle("teamNAme");

    QList<Item> books;
    books.push_back(*temp1);
    books.push_back(*temp2);
    books.push_back(*temp3);
    books.push_back(*temp4);
    books.push_back(*temp5);
    books.push_back(*temp6);

    return books;
}

int StudentManager::checkout(std::string user,QList<Item> checkoutBooks){
    //TODO
    removeCartItems(user);
    return -5;
}

bool StudentManager::removeCartItems(std::string user){
    //TODO
    return false;
}
