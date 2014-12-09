/********************************************************************************
** Form generated from reading UI file 'ownedbooks.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OWNEDBOOKS_H
#define UI_OWNEDBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OwnedBooks
{
public:
    QLabel *label;
    QWidget *widget;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_8;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *Title;
    QLabel *label_2;

    void setupUi(QWidget *OwnedBooks)
    {
        if (OwnedBooks->objectName().isEmpty())
            OwnedBooks->setObjectName(QStringLiteral("OwnedBooks"));
        OwnedBooks->resize(865, 699);
        label = new QLabel(OwnedBooks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        widget = new QWidget(OwnedBooks);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 80, 851, 531));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 500, 88, 27));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 20, 301, 41));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 70, 751, 391));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 735, 700));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 700));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 741, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton = new QPushButton(OwnedBooks);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(750, 90, 88, 27));
        label_6 = new QLabel(OwnedBooks);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        Title = new QLabel(OwnedBooks);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_2 = new QLabel(OwnedBooks);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));

        retranslateUi(OwnedBooks);

        QMetaObject::connectSlotsByName(OwnedBooks);
    } // setupUi

    void retranslateUi(QWidget *OwnedBooks)
    {
        OwnedBooks->setWindowTitle(QApplication::translate("OwnedBooks", "Form", 0));
        label->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("OwnedBooks", "Back to List", 0));
        label_9->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:26pt;\">Owned Items</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:16pt;\">Description</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:16pt;\">Price</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:16pt;\">Name</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:16pt;\">Type</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("OwnedBooks", "Sign Out", 0));
        label_6->setText(QApplication::translate("OwnedBooks", "TeamName \302\251Copyright 2014", 0));
        Title->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_2->setText(QApplication::translate("OwnedBooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class OwnedBooks: public Ui_OwnedBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OWNEDBOOKS_H
