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

    int addToPreviouslyPurchasedItems(std::string studentName, std::string itemKeys[], DataBase *db);
    int addToCart(std::string studentName, std::string itemKeys[], int itemCount, DataBase *db);
    int checkout(std::string user,QList<Item> checkoutBooks, DataBase *db);
    bool removeCartItems(std::string user);
    QList<Item> viewPurchasedItems(std::string studentName);
    QList<Item> viewCart(std::string studentName, DataBase* myDB);
    QList<Course> getEnrolledCourse(std::string user);
    QList<Item> getBooksFromCourse(QList<Course> regCourse);
};

#endif // STUDENTMANAGER_H
