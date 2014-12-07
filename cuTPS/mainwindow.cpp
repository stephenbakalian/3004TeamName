#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);

    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
void MainWindow::setCTMViewItems(std::string username)
{
    CTMViewTextsPage = new CTMViewTextbooks();
    CTMViewTextsPage->setUsername(username);
    this->setCentralWidget(CTMViewTextsPage);
}
void MainWindow::setStuViewItems(std::string username)
{
    StuViewTextsPage = new StudentViewTextbooks();
    StuViewTextsPage->setUsername(username);
    this->setCentralWidget(StuViewTextsPage);
}
void MainWindow::setViewLogin()
{
    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
void MainWindow::setViewError(QString errorMessage, int refPage, std::string username){
    errorPage = new Error();
    errorPage->setError(errorMessage, refPage);
    errorPage->setUsername(username);
    this->setCentralWidget(errorPage);
}
void MainWindow::setViewModItems(std::string username){
    ModTextPage = new ModifyTextbook();
    ModTextPage->setUsername(username);
    this->setCentralWidget(ModTextPage);
}
void MainWindow::setViewModItems(QString args[], std::string username){
    ModTextPage = new ModifyTextbook();
    ModTextPage->setData(args);
    ModTextPage->setUsername(username);
    this->setCentralWidget(ModTextPage);
}
void MainWindow::setViewCart(std::string username){
    cartPage = new Cart();
    cartPage->setUsername(username);
    this->setCentralWidget(cartPage);
}
void MainWindow::setViewOwnedItems(std::string username){
    ownedPage = new OwnedBooks();
    ownedPage->setUsername(username);
    this->setCentralWidget(ownedPage);
}
void MainWindow::setViewAdmin(){
    adminPage = new admin();
    this->setCentralWidget(adminPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
