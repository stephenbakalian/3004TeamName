#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "login.h"
#include "ctmviewtextbooks.h"
#include "error.h"
#include "modifytextbook.h"
#include "studentviewtextbooks.h"

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
    void setViewLogin();
    void setViewError(QString,int);
    void setViewModItems();
    ~MainWindow();

private:

    ModifyTextbook *ModTextPage;
    Login *loginPage;
    Error *errorPage;
    CTMViewTextbooks *CTMViewTextsPage;
    StudentViewTextbooks *StuViewTextsPage;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
