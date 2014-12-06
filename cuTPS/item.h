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

    void setTitle(std::string);
    void setAuthor(std::string);
    void setDescription(std::string);
    void setCourse(std::string);
    void setPurchaseDate(std::string);
private:
    std::string title;
    std::string author;
    std::string description;
    std::string course;
    std::string purchaseDate;
};

#endif // ITEM_H
