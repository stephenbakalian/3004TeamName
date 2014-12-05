#include "studentviewtextbooks.h"
#include "ui_studentviewtextbooks.h"
#include "mainwindow.h"
StudentViewTextbooks::StudentViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentViewTextbooks)
{
    ui->setupUi(this);
}

StudentViewTextbooks::~StudentViewTextbooks()
{
    delete ui;
}

void StudentViewTextbooks::on_pushButton_6_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}

void StudentViewTextbooks::on_pushButton_7_clicked()
{
    ((MainWindow*)parentWidget())->setViewCart();
}

void StudentViewTextbooks::on_pushButton_8_clicked()
{
    ((MainWindow*)parentWidget())->setViewOwnedItems();
}
