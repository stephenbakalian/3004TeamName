#ifndef SECTION_H
#define SECTION_H
#include "chapter.h"
class section : public Chapter{
public:
    section();
    std::string getChapter();
    void setChapter(std::string);
private:
    std::string chapter;

};

#endif // SECTION_H
