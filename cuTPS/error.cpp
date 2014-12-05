#include "error.h"
#include "ui_error.h"
#include "mainwindow.h"
Error::Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
}
void Error::setError(QString message, int pageNum){
    errorMessage=message;
    errorPage   =pageNum;
    if(errorPage==0){
        ui->pushButton_2->setVisible(false);
    }

}

Error::~Error()
{
    delete ui;
}

void Error::on_pushButton_clicked()
{
    switch(errorPage){
    case 0://loginPage
        ((MainWindow*)parentWidget())->setViewLogin();
        break;
    case 1://stuViewText
        ((MainWindow*)parentWidget())->setStuViewItems();
        break;
    case 2:
        ((MainWindow*)parentWidget())->setCTMViewItems();
        break;
    case 3:
        ((MainWindow*)parentWidget())->setViewCart();
        break;
    case 4:
        ((MainWindow*)parentWidget())->setViewModItems();
        break;
       default:
        ((MainWindow*)parentWidget())->setViewLogin();
    }
}

void Error::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
