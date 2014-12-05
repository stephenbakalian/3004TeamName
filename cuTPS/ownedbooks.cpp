#include "ownedbooks.h"
#include "ui_ownedbooks.h"
#include "mainwindow.h"
OwnedBooks::OwnedBooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnedBooks)
{
    ui->setupUi(this);
}

OwnedBooks::~OwnedBooks()
{
    delete ui;
}

void OwnedBooks::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems();
}

void OwnedBooks::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}
