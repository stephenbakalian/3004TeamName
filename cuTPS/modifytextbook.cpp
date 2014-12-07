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
    reqHandler = new RequestHandler(this);

    Item item;
    item.setAuthor(ui->author->text().toStdString());
    //item.setCourse(ui->course->text().toStdString());
    //TODO ADD course
    item.setDescription(ui->description->toPlainText().toStdString());
    item.setPrice(ui->price->text().toStdString());
    item.setTitle(ui->title->text().toStdString());

    int selected =  ui->type->currentIndex();
    switch (selected){
    case 0://textbook
        item.setType("textbook");
        break;
    case 1://chapter
        item.setType("chapter");
        break;
    case 2://section
        item.setType("section");
        break;
    }
    int resp = reqHandler->addItem(item);
    qDebug() << "Add to cart" << resp;
    switch (resp) {
    case -5:
        ((MainWindow*)parentWidget())->setViewError("Database connection error",4, username);
        break;
    case -4:
        ((MainWindow*)parentWidget())->setViewError("Unable to connect to the server... \n is it running?",0, username);
        break;
    case -3:
        ((MainWindow*)parentWidget())->setViewError("Opps/nSomething went very wrong",4, username);
        break;
    case -2:
        ((MainWindow*)parentWidget())->setViewError("Unknown Json Parsing Error",4,username);
        break;
    case 0://Socket Disconect
        break;
    case 1: //Successfull
        break;
    case 2: //Student logs in
        //Add to cart
        break;
    default:
        ((MainWindow*)parentWidget())->setViewError("An unhandeled error occured \n please contant a techincal assiant \n ERROR: " + resp,1, username);
    }
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

