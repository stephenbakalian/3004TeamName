#include "modifytextbook.h"
#include "ui_modifytextbook.h"

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
