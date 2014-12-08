#ifndef ITEM_H
#define ITEM_H

#include <string>
class Item
{
public:
    Item();
    std::string getTitle();
    std::string getAuthor();
    std::string getDescription();
    std::string getCourse();
    std::string getPurchaseDate();
    std::string getPrice();
    std::string getType();
    std::string getLength();
    std::string getISBN();

    void setISBN(std::string);
    void setTitle(std::string);
    void setAuthor(std::string);
    void setDescription(std::string);
    void setCourse(std::string);
    void setPurchaseDate(std::string);
    void setPrice(std::string);
    void setType(std::string);
    void setLength(std::string);

private:
    std::string ISBN;
    std::string title;
    std::string author;
    std::string description;
    std::string course;
    std::string purchaseDate;
    std::string price;
    std::string type;
    std::string length;

};

#endif // ITEM_H
