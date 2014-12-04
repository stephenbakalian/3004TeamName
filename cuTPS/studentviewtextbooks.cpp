#include "studentviewtextbooks.h"
#include "ui_studentviewtextbooks.h"

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
