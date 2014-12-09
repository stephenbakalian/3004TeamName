/********************************************************************************
** Form generated from reading UI file 'error.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERROR_H
#define UI_ERROR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Error
{
public:
    QLabel *Title;
    QWidget *widget;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Error)
    {
        if (Error->objectName().isEmpty())
            Error->setObjectName(QStringLiteral("Error"));
        Error->resize(862, 694);
        Title = new QLabel(Error);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        widget = new QWidget(Error);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 110, 851, 531));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 30, 351, 61));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 430, 88, 27));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(-110, 140, 481, 381));
        plainTextEdit = new QPlainTextEdit(widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(380, 160, 411, 251));
        label_4->raise();
        label_3->raise();
        pushButton->raise();
        plainTextEdit->raise();
        label_2 = new QLabel(Error);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        label_6 = new QLabel(Error);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label = new QLabel(Error);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        pushButton_2 = new QPushButton(Error);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(750, 90, 88, 27));
        label->raise();
        widget->raise();
        Title->raise();
        label_2->raise();
        label_6->raise();
        pushButton_2->raise();

        retranslateUi(Error);

        QMetaObject::connectSlotsByName(Error);
    } // setupUi

    void retranslateUi(QWidget *Error)
    {
        Error->setWindowTitle(QApplication::translate("Error", "Form", 0));
        Title->setText(QApplication::translate("Error", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Error", "<html><head/><body><p><span style=\" font-size:26pt;\">An error has occured:</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Error", "OK", 0));
        label_4->setText(QApplication::translate("Error", "<html><head/><body><p><img src=\":/new/prefix1/bookError.jpg\"/></p></body></html>", 0));
        plainTextEdit->setPlainText(QApplication::translate("Error", "Unable to connect to remote server", 0));
        label_2->setText(QApplication::translate("Error", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("Error", "TeamName \302\251Copyright 2014", 0));
        label->setText(QApplication::translate("Error", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("Error", "Sign Out", 0));
    } // retranslateUi

};

namespace Ui {
    class Error: public Ui_Error {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERROR_H
