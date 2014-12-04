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

void CTMViewTextbooks::on_pushButton_16_clicked()
{
    ((MainWindow*)parentWidget())->setViewModItems();
}
