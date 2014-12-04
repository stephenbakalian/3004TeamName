#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDialog>
#include <QObject>
#include <string>

#include "requesthandler.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    RequestHandler *reqHandler;
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();
    void socketStatus(int status);

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
