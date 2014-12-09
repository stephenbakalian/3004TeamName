#include "mainwindow.h"
#include <QDebug>

/**
 * Main displayof the application, this window is used to show every other page ontop of.
 *
 *@brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);

    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
//chaneg view to CTM view items
void MainWindow::setCTMViewItems(std::string username)
{
    CTMViewTextsPage = new CTMViewTextbooks();
    CTMViewTextsPage->setUsername(username);
    this->setCentralWidget(CTMViewTextsPage);
}
//change view to student view items
void MainWindow::setStuViewItems(std::string username)
{
    StuViewTextsPage = new StudentViewTextbooks();
    StuViewTextsPage->setUsername(username);
    this->setCentralWidget(StuViewTextsPage);
}
//change view to login screen
void MainWindow::setViewLogin()
{
    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
//Change the view to error page
void MainWindow::setViewError(QString errorMessage, int refPage, std::string username){
    errorPage = new Error();
    errorPage->setError(errorMessage, refPage);
    errorPage->setUsername(username);
    this->setCentralWidget(errorPage);
}
//change the view to modify a given item
void MainWindow::setViewModItems(std::string username,Item showItem){
    ModTextPage = new ModifyTextbook();
    ModTextPage->setUsername(username);
    ModTextPage->setData(showItem);
    this->setCentralWidget(ModTextPage);
}
//change view to create a new item
void MainWindow::setViewModItems(std::string username){
    ModTextPage = new ModifyTextbook();
    ModTextPage->setUsername(username);
    this->setCentralWidget(ModTextPage);
}
//change view to view student's cart
void MainWindow::setViewCart(std::string username){
    cartPage = new Cart();
    cartPage->setUsername(username);
    this->setCentralWidget(cartPage);
}
//change view to view owned items
void MainWindow::setViewOwnedItems(std::string username){
    ownedPage = new OwnedBooks();
    ownedPage->setUsername(username);
    this->setCentralWidget(ownedPage);
}
//change view to admin's
void MainWindow::setViewAdmin(){
    adminPage = new admin();
    this->setCentralWidget(adminPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//logout button (here for templating to otber classes)
void MainWindow::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
