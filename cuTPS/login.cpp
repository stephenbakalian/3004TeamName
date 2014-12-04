#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"

//For testing
#include <QMessageBox>

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
    reqHandler->Login("student");
}

void Login::socketStatus(int status) {
    QMessageBox alert;

    switch (status) {
    case -1:
        qDebug() << "status -1";
        alert.setText("Failed.");
        alert.exec();
        return;
    case 0:
        qDebug() << "status 0";
        alert.setText("Socket disconnected");
        alert.exec();
        return;
    case 1:
        qDebug() << "status 1";
        alert.setText("Successful");
        alert.exec();
        ((MainWindow*)parentWidget())->setStuViewItems();

        return;
    default:
        qDebug() << "status defult";
        alert.setText("Unhandled status");
        alert.exec();
        break;
    }
}
