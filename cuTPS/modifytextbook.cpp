#include "modifytextbook.h"
#include "ui_modifytextbook.h"
#include "mainwindow.h"
ModifyTextbook::ModifyTextbook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyTextbook)
{
    ui->setupUi(this);
}

ModifyTextbook::~ModifyTextbook()
{
    delete ui;
}

void ModifyTextbook::on_pushButton_clicked()
{

}

void ModifyTextbook::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setCTMViewItems();
}

void ModifyTextbook::on_pushButton_3_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
