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
#include <string>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setStuViewItems();
    void setCTMViewItems();
    void setViewOwnedItems();
    void setViewLogin();
    void setViewError(QString,int);
    void setViewModItems();
    void setViewModItems(QString[]);
    void setViewCart();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:

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
