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
std::string Item::getPrice(){
    return price;
}
std::string Item::getType(){
    return type;
}
std::string Item::getLength(){
    return length;
}
std::string Item::getISBN(){
    return ISBN;
}


void Item::setISBN(std::string newISBN){
    ISBN=newISBN;
}
void Item::setTitle(std::string newLength){
    length=newLength;
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
void Item::setPrice(std::string newPrice){
    price=newPrice;
}
void Item::setType(std::string newType){
    type=newType;
}
