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


}


void Login::on_pushButton_released()
{

    reqHandler = new RequestHandler(this);
    int resp = reqHandler->Login((ui->LoginUsername->text().toStdString()));
    qDebug() << "Login Status" << resp;
    switch (resp) {
    case -10:
        ((MainWindow*)parentWidget())->setViewError("Opps/nSomething went very wrong",0);
    case -2:
        ((MainWindow*)parentWidget())->setViewError("Unknown Json Parsing Error",0);
        break;
    case -1:
        ui->error->setText("Incorrect Username");
        ui->error->setStyleSheet("QLabel { font-size : 16; color : red; }");
        break;

    case 0://Socket Disconect
        break;
    case 1: //Successfull
        break;
    case 2: //Student logs in
        ((MainWindow*)parentWidget())->setStuViewItems();
        break;
    case 3: //CTM logs in
        ((MainWindow*)parentWidget())->setCTMViewItems();
        break;
    case 4: //Admin Logs in
        break;
    }
}
