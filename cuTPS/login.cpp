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
    qDebug() << "button login triggered.";
    reqHandler = new RequestHandler(this);
    reqHandler->Login((ui->LoginUsername->text().toStdString()));
}

void Login::socketStatus(int status) {
    qDebug() << (status);
    switch (status) {
    case -1:
        ui->label_2->setText("Incorrect username or Password");
        break;

    case 0://Socket Disconect
        break;

    case 1: //Successfull
        ((MainWindow*)parentWidget())->setStuViewItems();
        break;

    default: //General Server Error
        ((MainWindow*)parentWidget())->setViewError("Unable to Connect to server",0);
        break;
    }
}
