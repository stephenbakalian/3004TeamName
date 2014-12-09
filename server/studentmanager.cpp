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

int StudentManager::addToCart(std::string studentName, QList<Item> item, DataBase *myDB) {

    int success = -5;
    QList<Item>::iterator i;

    for (i = item.begin(); i != item.end(); ++i){
        qDebug() << QString::fromStdString(i->getISBN());
           success = myDB->createCart(QString::fromStdString(studentName), QString::fromStdString(i->getISBN()));
    }

    return success;
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
    removeCartItems(studentName);

    return books;

}

QList<Item> StudentManager::viewCart(std::string studentName, DataBase *myDB) {


    QList<Item> item = myDB->getCart(QString::fromStdString(studentName));
    QList<Item>::iterator i;
    QList<Item>::iterator c;
    QList<Item> books;

    QList <Item> temp = myDB->getAllItems();

    //for (c = temp.begin(); c != temp.end(); ++c){
        for (i = item.begin(); i != item.end(); ++i){
      //      if (c->getISBN() == i->getISBN()){
            //qDebug() << QString::fromStdString(i->getISBN());
                   //books.push_back(*i);
            }
        //}
    //}



    return books;
}

int StudentManager::checkout(std::string user,QList<Item> checkoutBooks, DataBase* myDB){

    int success = -5;

    QList<Item>::iterator i;

    for (i = checkoutBooks.begin(); i != checkoutBooks.end(); ++i){
        myDB->createPurchaseRelation(QString::fromStdString(user), QString::fromStdString(i->getISBN()));
    }

    success = myDB->deleteCart(QString::fromStdString(user));
    removeCartItems(user);
    return success;
}

bool StudentManager::removeCartItems(std::string user){
    //TODO
    return false;
}

QList<Item> StudentManager::getBooksFromCourse(QList<Course> regCourse, DataBase* myDB){

    QList<Item> books;
    QList<Item> item;
    QList<Course> course = regCourse;
    QList<Item>::iterator i;
    QList<Course>::iterator c;

    if (regCourse.isEmpty()){
        return books;
    }

    item = myDB->getAllItems();

    for (i = item.begin(); i != item.end(); ++i){
               books.push_back(*i);
    }

    return books;
}

QList<Course> StudentManager::getEnrolledCourse(std::string user, DataBase* myDB){

    QList<Course> course = myDB->getCourseRelation(QString::fromStdString(user));

    return course;

}

int StudentManager::emptyCart(std::string username, DataBase *db){
    return -1;
}
