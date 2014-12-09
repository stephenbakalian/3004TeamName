#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>
#include <QList>

#include "item.h"
#include "course.h"

class StudentManager
{
public:
    StudentManager();

    int addToPreviouslyPurchasedItems(std::string studentName, std::string itemKeys[]);
    int addToCart(std::string studentName, std::string itemKeys[]);
    int checkout(std::string user,QList<Item> checkoutBooks);
    bool removeCartItems(std::string user);
    QList<Item> viewPurchasedItems(std::string studentName);
    QList<Item> viewCart(std::string studentName);
    QList<Course> getEnrolledCourse(std::string user);
    QList<Item> getBooksFromCourse(QList<Course> regCourse);
};

#endif // STUDENTMANAGER_H
