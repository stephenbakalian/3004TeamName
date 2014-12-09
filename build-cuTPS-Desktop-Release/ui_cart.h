/********************************************************************************
** Form generated from reading UI file 'cart.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CART_H
#define UI_CART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cart
{
public:
    QLabel *Title;
    QLabel *label;
    QWidget *widget;
    QPushButton *pushButton_2;
    QLabel *label_9;
    QPushButton *pushButton_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_3;
    QPushButton *pushButton_4;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_10;
    QLabel *totalPrice;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Cart)
    {
        if (Cart->objectName().isEmpty())
            Cart->setObjectName(QStringLiteral("Cart"));
        Cart->resize(862, 691);
        Title = new QLabel(Cart);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label = new QLabel(Cart);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        widget = new QWidget(Cart);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 89, 851, 531));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(730, 490, 88, 27));
        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 10, 181, 51));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(340, 490, 171, 27));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(30, 80, 761, 371));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 745, 700));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 700));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 751, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 5, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 490, 91, 27));
        horizontalLayoutWidget = new QWidget(widget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(250, 460, 331, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        totalPrice = new QLabel(horizontalLayoutWidget);
        totalPrice->setObjectName(QStringLiteral("totalPrice"));

        horizontalLayout->addWidget(totalPrice);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_6 = new QLabel(Cart);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label_2 = new QLabel(Cart);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        pushButton = new QPushButton(Cart);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(750, 90, 88, 27));
        label->raise();
        widget->raise();
        Title->raise();
        label_6->raise();
        label_2->raise();
        pushButton->raise();

        retranslateUi(Cart);

        QMetaObject::connectSlotsByName(Cart);
    } // setupUi

    void retranslateUi(QWidget *Cart)
    {
        Cart->setWindowTitle(QApplication::translate("Cart", "Form", 0));
        Title->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label->setText(QApplication::translate("Cart", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("Cart", "Back to List", 0));
        label_9->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:26pt;\">Cart:</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("Cart", "Purchase Cart", 0));
        label_4->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:16pt;\">Price</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:16pt;\">Type</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:16pt;\">Purchase Date</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:16pt;\">Desciption</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:16pt;\">Name</span></p></body></html>", 0));
        pushButton_4->setText(QApplication::translate("Cart", "Empty Cart", 0));
        label_10->setText(QApplication::translate("Cart", "Total Price:", 0));
        totalPrice->setText(QString());
        label_6->setText(QApplication::translate("Cart", "TeamName \302\251Copyright 2014", 0));
        label_2->setText(QApplication::translate("Cart", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        pushButton->setText(QApplication::translate("Cart", "Sign Out", 0));
    } // retranslateUi

};

namespace Ui {
    class Cart: public Ui_Cart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CART_H
