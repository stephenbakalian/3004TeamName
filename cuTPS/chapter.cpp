#include "chapter.h"

/**
 * Item type used to store a chapter (part of textbook)
 *@brief Chapter::Chapter
 */
Chapter::Chapter()
{


}
void Chapter::setTextbookName(std::string newName){
    textbookName=newName;
}
std::string Chapter::getTextbookName(){
    return textbookName;
}
