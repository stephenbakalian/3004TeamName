#include "ctmviewtextbooks.h"
#include "ui_ctmviewtextbooks.h"
#include "mainwindow.h"
CTMViewTextbooks::CTMViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTMViewTextbooks)
{
    ui->setupUi(this);
}

CTMViewTextbooks::~CTMViewTextbooks()
{
    delete ui;
}

void CTMViewTextbooks::setUsername(std::string user){
    username=user;
}

void CTMViewTextbooks::on_pushButton_16_clicked() //edit button had been pressed
{
    QString temp[]= {"1","THIS IS A PLACEHOLDER"};
    ((MainWindow*)parentWidget())->setViewModItems(temp, username);
}

void CTMViewTextbooks::on_pushButton_3_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}

void CTMViewTextbooks::on_pushButton_clicked()//new Button has been pressed
{
    ((MainWindow*)parentWidget())->setViewModItems(username);

}
