#include "chapter.h"

Chapter::Chapter()
{


}
void Chapter::setTextbookName(std::string newName){
    textbookName=newName;
}
std::string Chapter::getTextbookName(){
    return textbookName;
}
