#include "studentmanager.h"

//================================================================
//          Methods to manage the student user
//================================================================


StudentManager::StudentManager()
{
}

int StudentManager::addToPreviouslyPurchasedItems(std::string studentName, std::string itemKeys[], DataBase *myDB) {
    //TODO
    //myDB->createPurchaseRelation();
    return -5;
}

int StudentManager::addToCart(std::string studentName, QList<Item> items, DataBase *myDB) {
    //TODO
    for (int i = 0; i < items.size(); i++){
        //myDB->createCart(QString::fromStdString(studentName), QString::fromStdString(itemKeys[i]));
    }
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
    books.push_back(*temp4);    //TODO
    removeCartItems(studentName);
    //return -5;
    return books;

}

QList<Item> StudentManager::viewCart(std::string studentName, DataBase *myDB) {

    myDB->getCart(QString::fromStdString(studentName));
/*    Item temp1;
    Item temp2;
    Item temp3;
    Item temp4;
    Item temp5;
    Item temp6;
    temp1.setTitle("HOW TO WIN at chess");
    temp2.setTitle("Batman beyond");
    temp3.setTitle("waffles are nigh");
    temp4.setTitle("Hai");
    temp5.setTitle("too many cooks");
    temp6.setTitle("teamNAme");


    books.push_back(temp1);
    books.push_back(temp2);
    books.push_back(temp3);
    books.push_back(temp4);
    books.push_back(temp5);
    books.push_back(temp6);*/
    QList<Item> books;
    return books;
}

int StudentManager::checkout(std::string user,QList<Item> checkoutBooks, DataBase* myDB){
    //TODO
    for (int i = 0; i < checkoutBooks.length(); i++){
        //myDB->createPurchaseRelation(QString::fromStdString(user), checkoutBooks.)
    }

    myDB->deleteCart(QString::fromStdString(user));
    removeCartItems(user);
    return -5;
}

bool StudentManager::removeCartItems(std::string user){
    //TODO
    return false;
}

QList<Item> StudentManager::getBooksFromCourse(QList<Course> regCourse, DataBase* myDB){

    QList<Item> books;
    QList<Item> item;
    QList<Item>::iterator i;

    item = myDB->getAllItems();

    for (i = item.begin(); i != item.end(); ++i){
        books.push_back(*i);
    }

    if (regCourse.isEmpty()){
        return books;
    }

    return books;
}

QList<Course> StudentManager::getEnrolledCourse(std::string user){
    Course temp1;
    temp1.setCourseCode("hi");

    QList<Course> courses;
    courses.push_back(temp1);
    return courses;
}

int StudentManager::emptyCart(std::string username, DataBase *db){
    return -1;
}
