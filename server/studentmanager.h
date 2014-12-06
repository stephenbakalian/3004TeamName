#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <string>

class StudentManager
{
public:
    StudentManager();

    int addToPreviouslyPurchasedItems(std::string studentName, std::string itemKeys[]);
    int addToCart(std::string studentName, std::string itemKeys[]);
};

#endif // STUDENTMANAGER_H
