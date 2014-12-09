/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QLabel *Title;
    QLabel *label_6;
    QLabel *label_2;
    QWidget *widget;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QStringLiteral("admin"));
        admin->resize(863, 698);
        label = new QLabel(admin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        pushButton = new QPushButton(admin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(750, 90, 88, 27));
        Title = new QLabel(admin);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_6 = new QLabel(admin);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label_2 = new QLabel(admin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        widget = new QWidget(admin);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 89, 851, 531));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 10, 381, 71));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 230, 481, 81));
        label->raise();
        Title->raise();
        label_6->raise();
        label_2->raise();
        widget->raise();
        pushButton->raise();

        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QWidget *admin)
    {
        admin->setWindowTitle(QApplication::translate("admin", "Form", 0));
        label->setText(QApplication::translate("admin", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        pushButton->setText(QApplication::translate("admin", "Sign Out", 0));
        Title->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("admin", "TeamName \302\251Copyright 2014", 0));
        label_2->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:26pt;\">System Administrator</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("admin", "<html><head/><body><p><span style=\" font-size:16pt;\">This page is a placeholder, it's pretty great.</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
