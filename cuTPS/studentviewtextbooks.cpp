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

void StudentViewTextbooks::on_pushButton_5_clicked()
{
    reqHandler = new RequestHandler(this);
    //TODO loop seleteditems
    std::string checkedItems[4];
    checkedItems[0]="test";
    checkedItems[1]="waffles";
    int resp = reqHandler->AddToCart(checkedItems, ((MainWindow*)parentWidget())->getUsername());
    qDebug() << "Add to cart" << resp;
    switch (resp) {
    case -5:
        ((MainWindow*)parentWidget())->setViewError("Database connection error",1);
        break;
    case -4:
        ((MainWindow*)parentWidget())->setViewError("Unable to connect to the server... \n is it running?",0);
        break;
    case -3:
        ((MainWindow*)parentWidget())->setViewError("Opps/nSomething went very wrong",1);
        break;
    case -2:
        ((MainWindow*)parentWidget())->setViewError("Unknown Json Parsing Error",1);
        break;
    case 0://Socket Disconect
        break;
    case 1: //Successfull
        break;
    case 2: //Student logs in
        //Add to cart
        break;
    }
}
