#include "item.h"

Item::Item()
{

}
std::string Item::getTitle(){
    return title;
}
std::string Item::getAuthor(){
    return author;
}
std::string Item::getDescription(){
    return description;
}
std::string Item::getCourse(){
    return course;
}
std::string Item::getPurchaseDate(){
    return purchaseDate;
}

void Item::setTitle(std::string newTitle){
    title=newTitle;
}
void Item::setAuthor(std::string newAuthor){
    author=newAuthor;
}
void Item::setDescription(std::string newDescription){
    description=newDescription;
}
void Item::setCourse(std::string newCourse){
    course=newCourse;
}
void Item::setPurchaseDate(std::string newPurchaseDate){
    purchaseDate=newPurchaseDate;
}
