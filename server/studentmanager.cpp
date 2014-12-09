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
    books.push_back(*temp4);    //TODO
    removeCartItems(studentNames);
    //return -5;
    return books;

}

QList<Item> StudentManager::viewCart(std::string studentName) {
    Item temp1;
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

    QList<Item> books;
    books.push_back(temp1);
    books.push_back(temp2);
    books.push_back(temp3);
    books.push_back(temp4);
    books.push_back(temp5);
    books.push_back(temp6);

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

QList<Item> StudentManager::getBooksFromCourse(QList<Course> regCourse){
    QList<Item> books;
    if (regCourse.isEmpty()){
        return books;
    }
    Item temp1;
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
    books.push_back(temp6);
    return books;
}

QList<Course> StudentManager::getEnrolledCourse(std::string user){
    Course temp1;
    temp1.setCourseCode("hi");

    QList<Course> courses;
    courses.push_back(temp1);
    return courses;
}
