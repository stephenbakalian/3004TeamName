#ifndef CHAPTER_H
#define CHAPTER_H
#include "item.h"

class Chapter : public Item
{
public:
    Chapter();
    std::string getTextbookName();
    void setTextbookName(std::string);
private:
    std::string textbookName;

};

#endif // CHAPTER_H
