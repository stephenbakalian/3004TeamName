#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
    {
    ui->setupUi(this);

    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
void MainWindow::setCTMViewItems()
{
    CTMViewTextsPage = new CTMViewTextbooks();
    this->setCentralWidget(CTMViewTextsPage);
}
void MainWindow::setStuViewItems()
{
    StuViewTextsPage = new StudentViewTextbooks();
    this->setCentralWidget(StuViewTextsPage);
}
void MainWindow::setViewLogin()
{
    loginPage = new Login();
    this->setCentralWidget(loginPage);
}
void MainWindow::setViewError(QString errorMessage, int refPage){
    errorPage = new Error();
    errorPage->setError(errorMessage, refPage);
    this->setCentralWidget(errorPage);
}
void MainWindow::setViewModItems(){
    ModTextPage = new ModifyTextbook();
    this->setCentralWidget(ModTextPage);
}
void MainWindow::setViewCart(){
    cartPage = new Cart();
    this->setCentralWidget(cartPage);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}
