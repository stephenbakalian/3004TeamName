#include "admin.h"
#include "ui_admin.h"
#include "mainwindow.h"


/**
 * Admin Page (Just a placeholder)
 *
 * @brief admin::admin
 * @param parent parent widget
 */
admin::admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
}

admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}
