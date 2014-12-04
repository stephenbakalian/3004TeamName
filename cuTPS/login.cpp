#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
Login::Login(QWidget *parent) :
    QWidget(parent), ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems();
}
