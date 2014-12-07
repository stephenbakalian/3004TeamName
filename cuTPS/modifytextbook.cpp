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

void ModifyTextbook::setUsername(std::string user){
    username=user;
}


void ModifyTextbook::on_pushButton_clicked()
{

}
void ModifyTextbook::setData(QString* info)
{
    ui->type->setCurrentIndex(info[0].toInt());
    updateAvailableFeilds();
    ui->title->setText(info[1]);
}
void ModifyTextbook::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setCTMViewItems(username);
}

void ModifyTextbook::on_pushButton_3_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}

void ModifyTextbook::on_type_currentIndexChanged(const QString &arg1)
{
    updateAvailableFeilds();

}
void ModifyTextbook::updateAvailableFeilds(){
    int selected =  ui->type->currentIndex();
    switch (selected){
    case 0://textbook
        ui->chapter->setEnabled(false);
        ui->textbook->setEnabled(false);
        break;
    case 1://chapter
        ui->chapter->setEnabled(false);
        ui->textbook->setEnabled(true);
        break;

    case 2://section
        ui->chapter->setEnabled(true);
        ui->textbook->setEnabled(true);
        break;

    }

}

void ModifyTextbook::on_type_activated(int index)
{

}

