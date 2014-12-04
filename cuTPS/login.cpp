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
        ui->error->setText("Incorrect Username");
        ui->error->setStyleSheet("QLabel { font-size : 16; color : red; }");

        break;

    case 0://Socket Disconect
        break;

<<<<<<< HEAD
    case 1: //Successfull
        break;

    case 2: //Student logs in
=======
    case 2: //Successfull
>>>>>>> 9e9da2906136b708dcbd266df084131ccc4bbac4
        ((MainWindow*)parentWidget())->setStuViewItems();
        break;
    case 3: //CTM logs in
        ((MainWindow*)parentWidget())->setCTMViewItems();
        break;
    case 4: //Admin Logs in
        break;

    default: //General Server Error
        ((MainWindow*)parentWidget())->setViewError("Unable to Connect to server",0);
        break;
    }
}
