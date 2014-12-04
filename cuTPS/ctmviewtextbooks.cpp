#include "ctmviewtextbooks.h"
#include "ui_ctmviewtextbooks.h"

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
