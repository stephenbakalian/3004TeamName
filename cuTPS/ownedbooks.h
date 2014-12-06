#ifndef OWNEDBOOKS_H
#define OWNEDBOOKS_H
#include "item.h"
#include <QWidget>
#include "requesthandler.h"

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
    void showItems(Item[]);

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();

private:
    Ui::OwnedBooks *ui;
};

#endif // OWNEDBOOKS_H
