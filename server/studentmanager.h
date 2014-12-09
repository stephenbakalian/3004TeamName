#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>
#include <QList>

#include "item.h"
#include "course.h"
#include "database.h"

class StudentManager
{
public:
    StudentManager();

    int addToCart(std::string studentName, QList<Item> item, DataBase *db);
    int checkout(std::string user,QList<Item> checkoutBooks, DataBase *db);
    int emptyCart(std::string username, DataBase *db);
    bool removeCartItems(std::string user);
    QList<Item> viewPurchasedItems(std::string studentName, DataBase* myDB);
    QList<Item> viewCart(std::string studentName, DataBase* myDB);
    QList<Course> getEnrolledCourse(std::string user, DataBase* myDB);
    QList<Item> getBooksFromCourse(QList<Course> regCourse, DataBase* myDB);
};

#endif // STUDENTMANAGER_H
