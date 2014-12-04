#include "cart.h"
#include "ui_cart.h"
#include "mainwindow.h"
Cart::Cart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
}

Cart::~Cart()
{
    delete ui;
}

void Cart::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}

void Cart::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems();

}
