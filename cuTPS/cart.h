#ifndef CART_H
#define CART_H

#include <QWidget>

namespace Ui {
class Cart;
}

class Cart : public QWidget
{
    Q_OBJECT

public:
    explicit Cart(QWidget *parent = 0);
    ~Cart();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Cart *ui;
};

#endif // CART_H
