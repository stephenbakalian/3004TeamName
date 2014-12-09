#include "error.h"
#include "ui_error.h"
#include "mainwindow.h"


/**
 * Page used to show errors
 * @brief Error::Error
 * @param parent
 */
Error::Error(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Error)
{
    ui->setupUi(this);
}
//this sets the display messagefor when page is loaded
void Error::setError(QString message, int pageNum){
    errorMessage=message;
    errorPage   =pageNum;
    if(errorPage==0){
        ui->pushButton_2->setVisible(false);
    }
    ui->plainTextEdit->setPlainText(message);
}

//sets the name of the ucurrent user
void Error::setUsername(std::string user){
    username=user;
}

Error::~Error()
{
    delete ui;
}

//OK button pressed -> given errorPage number redirects to the page it was given to go to
void Error::on_pushButton_clicked()
{
    switch(errorPage){
    case 0://loginPage
        ((MainWindow*)parentWidget())->setViewLogin();
        break;
    case 1://stuViewText
        ((MainWindow*)parentWidget())->setStuViewItems(username);
        break;
    case 2:
        ((MainWindow*)parentWidget())->setCTMViewItems(username);
        break;
    case 3:
        ((MainWindow*)parentWidget())->setViewCart(username);
        break;
    case 4:
        ((MainWindow*)parentWidget())->setViewModItems(username);
        break;
       default:
        ((MainWindow*)parentWidget())->setViewLogin();
    }
}
//logout pressed send to login page
void Error::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
