#ifndef CART_H
#define CART_H
#include "item.h"
#include <QWidget>
#include <QList>

#include "requesthandler.h"

namespace Ui {
class Cart;
}

class Cart : public QWidget
{
    Q_OBJECT

public:
    RequestHandler *reqHandler;
    explicit Cart(QWidget *parent = 0);
    ~Cart();
    void showItems(QList<Item>);
    void setUsername(std::string username);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Cart *ui;
    std::string username;
    void updateUI();
};

#endif // CART_H
