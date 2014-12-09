#ifndef OWNEDBOOKS_H
#define OWNEDBOOKS_H
#include "item.h"
#include <QWidget>
#include "requesthandler.h"
#include <QList>

namespace Ui {
class OwnedBooks;
}

class OwnedBooks : public QWidget
{
    Q_OBJECT

public:
    RequestHandler *reqHandler;
    explicit OwnedBooks(QWidget *parent = 0);
    ~OwnedBooks();
    void showItems(QList<Item>);
    void setUsername(std::string username);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::OwnedBooks *ui;
    std::string username;
    void updateUI();
};

#endif // OWNEDBOOKS_H
