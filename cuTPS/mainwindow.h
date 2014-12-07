#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "login.h"
#include "ctmviewtextbooks.h"
#include "error.h"
#include "modifytextbook.h"
#include "studentviewtextbooks.h"
#include "cart.h"
#include "ownedbooks.h"
#include "admin.h"
#include <string>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setStuViewItems(std::string usernames);
    void setCTMViewItems(std::string usernames);
    void setViewOwnedItems(std::string usernames);
    void setViewLogin();
    void setViewError(QString,int, std::string usernames);
    void setViewModItems(std::string usernames);
    void setViewModItems(QString[], std::string usernames);
    void setViewCart(std::string usernames);
    void setViewAdmin();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    admin *adminPage;
    ModifyTextbook *ModTextPage;
    Login *loginPage;
    Error *errorPage;
    OwnedBooks *ownedPage;
    CTMViewTextbooks *CTMViewTextsPage;
    StudentViewTextbooks *StuViewTextsPage;
    Cart *cartPage;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
