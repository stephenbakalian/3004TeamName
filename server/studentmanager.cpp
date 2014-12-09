#include "studentmanager.h"

//================================================================
//          Methods to manage the student user
//================================================================


StudentManager::StudentManager()
{
}

int StudentManager::addToCart(std::string studentName, QList<Item> item, DataBase *myDB) {

    int success = -1;
    QList<Item>::iterator i;

    for (i = item.begin(); i != item.end(); ++i){
        qDebug() << QString::fromStdString(i->getISBN());
           success = myDB->createCart(QString::fromStdString(studentName), QString::fromStdString(i->getISBN()));
    }

    return success;
}

QList<Item> StudentManager::viewPurchasedItems(std::string studentName, DataBase* myDB) {

    /*QList<Item> item = myDB->getCart(QString::fromStdString(studentName));
    QList<Item>::iterator i;*/
    QList<Item> books;
    return books;

}

QList<Item> StudentManager::viewCart(std::string studentName, DataBase *myDB) {


    QList<Item> item = myDB->getCart(QString::fromStdString(studentName));
    QList<Item>::iterator i;
    QList<Item> books;

    for (i = item.begin(); i != item.end(); ++i){
            //qDebug() << QString::fromStdString(i->getISBN());
            books.push_back(myDB->getItem(QString::fromStdString(i->getISBN())));
    }

    return books;
}

int StudentManager::checkout(std::string user,QList<Item> checkoutBooks, DataBase* myDB){

    int success = -1;

    QList<Item>::iterator i;

    for (i = checkoutBooks.begin(); i != checkoutBooks.end(); ++i){
        myDB->createPurchaseRelation(QString::fromStdString(user), QString::fromStdString(i->getISBN()));
    }

    success = emptyCart(user, myDB);
    return success;
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

    int success = -1;

    success = db->deleteCart(QString::fromStdString(username));

    return success;
}
