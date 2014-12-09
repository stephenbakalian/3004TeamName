/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label_3;
    QWidget *widget;
    QLabel *label_5;
    QFrame *line;
    QLabel *error;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *LoginUsername;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *Title;
    QLabel *label_6;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(855, 693);
        label_3 = new QLabel(Login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 0, 461, 71));
        label_3->setLineWidth(0);
        widget = new QWidget(Login);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-11, 89, 871, 531));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(170, 290, 531, 231));
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(-880, 290, 1751, 231));
        line->setLayoutDirection(Qt::LeftToRight);
        line->setAutoFillBackground(true);
        line->setFrameShadow(QFrame::Raised);
        line->setLineWidth(1000);
        line->setFrameShape(QFrame::HLine);
        error = new QLabel(widget);
        error->setObjectName(QStringLiteral("error"));
        error->setGeometry(QRect(360, 250, 121, 31));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 220, 85, 27));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 170, 168, 51));
        LoginUsername = new QLineEdit(widget);
        LoginUsername->setObjectName(QStringLiteral("LoginUsername"));
        LoginUsername->setGeometry(QRect(310, 180, 371, 31));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 291, 141));
        line->raise();
        label_5->raise();
        error->raise();
        LoginUsername->raise();
        pushButton->raise();
        label->raise();
        LoginUsername->raise();
        label_2->raise();
        label_4 = new QLabel(Login);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 0, 871, 701));
        Title = new QLabel(Login);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_6 = new QLabel(Login);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label_4->raise();
        Title->raise();
        label_3->raise();
        widget->raise();
        label_6->raise();

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Form", 0));
        label_3->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("Login", "<html><head/><body bgcolor=#FFFFFF><p><img src=\":/new/prefix1/CarletonLibrary.jpg\" height=\"250\"/></p></body></html>\342\200\235<body>", 0));
        error->setText(QApplication::translate("Login", "<html><head/><body><p><br/></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Login", "Sign In", 0));
        label->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt;\">User Name:</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt;\">Welcome to cuTPS</span></p><p><span style=\" font-size:24pt;\">Please Login</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("Login", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        Title->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("Login", "TeamName \302\251Copyright 2014", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
