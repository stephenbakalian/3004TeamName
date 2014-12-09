/********************************************************************************
** Form generated from reading UI file 'ctmviewtextbooks.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTMVIEWTEXTBOOKS_H
#define UI_CTMVIEWTEXTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTMViewTextbooks
{
public:
    QLabel *label_2;
    QWidget *widget;
    QPushButton *pushButton_16;
    QPushButton *pushButton;
    QFrame *line;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *itemGrid;
    QLabel *NameTitle;
    QLabel *TypeTitle;
    QLabel *CourseTitle;
    QFrame *line_19;
    QLabel *label_63;
    QLabel *label;
    QLabel *Title;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QLabel *SelectedCourse;
    QLabel *SelectedType;
    QLabel *label_25;
    QLabel *label_18;
    QLabel *label_21;
    QLabel *SelectedLength;
    QLabel *label_20;
    QLabel *SelectedTexbook;
    QLabel *SelectedChapter;
    QLabel *SelectedPrice;
    QLabel *label_19;
    QLabel *label_22;
    QLabel *text;
    QLabel *SelectedTitle;
    QLabel *label_16;
    QLabel *SelectedAuthor;
    QLabel *label_23;
    QLabel *SelectedISBN;
    QTextBrowser *SelectedDescription;

    void setupUi(QWidget *CTMViewTextbooks)
    {
        if (CTMViewTextbooks->objectName().isEmpty())
            CTMViewTextbooks->setObjectName(QStringLiteral("CTMViewTextbooks"));
        CTMViewTextbooks->resize(862, 694);
        label_2 = new QLabel(CTMViewTextbooks);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        label_2->setLineWidth(0);
        widget = new QWidget(CTMViewTextbooks);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 80, 851, 531));
        pushButton_16 = new QPushButton(widget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(530, 500, 251, 31));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(147, 500, 161, 31));
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(480, 80, 20, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 80, 461, 411));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 445, 700));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 700));
        verticalLayoutWidget_3 = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 451, 431));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        itemGrid = new QGridLayout();
        itemGrid->setObjectName(QStringLiteral("itemGrid"));
        NameTitle = new QLabel(verticalLayoutWidget_3);
        NameTitle->setObjectName(QStringLiteral("NameTitle"));

        itemGrid->addWidget(NameTitle, 0, 0, 1, 1);

        TypeTitle = new QLabel(verticalLayoutWidget_3);
        TypeTitle->setObjectName(QStringLiteral("TypeTitle"));

        itemGrid->addWidget(TypeTitle, 0, 2, 1, 1);

        CourseTitle = new QLabel(verticalLayoutWidget_3);
        CourseTitle->setObjectName(QStringLiteral("CourseTitle"));

        itemGrid->addWidget(CourseTitle, 0, 1, 1, 1);


        verticalLayout_3->addLayout(itemGrid);

        scrollArea->setWidget(scrollAreaWidgetContents);
        verticalLayoutWidget_3->raise();
        line_19 = new QFrame(CTMViewTextbooks);
        line_19->setObjectName(QStringLiteral("line_19"));
        line_19->setGeometry(QRect(870, 430, 3, 27));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);
        label_63 = new QLabel(CTMViewTextbooks);
        label_63->setObjectName(QStringLiteral("label_63"));
        label_63->setGeometry(QRect(350, 660, 181, 31));
        label = new QLabel(CTMViewTextbooks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        Title = new QLabel(CTMViewTextbooks);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_3 = new QLabel(CTMViewTextbooks);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 521, 81));
        pushButton_3 = new QPushButton(CTMViewTextbooks);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(750, 90, 88, 27));
        SelectedCourse = new QLabel(CTMViewTextbooks);
        SelectedCourse->setObjectName(QStringLiteral("SelectedCourse"));
        SelectedCourse->setGeometry(QRect(570, 380, 290, 16));
        SelectedType = new QLabel(CTMViewTextbooks);
        SelectedType->setObjectName(QStringLiteral("SelectedType"));
        SelectedType->setGeometry(QRect(570, 230, 291, 16));
        label_25 = new QLabel(CTMViewTextbooks);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(510, 170, 51, 16));
        label_18 = new QLabel(CTMViewTextbooks);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(510, 260, 51, 16));
        label_21 = new QLabel(CTMViewTextbooks);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(510, 350, 41, 16));
        SelectedLength = new QLabel(CTMViewTextbooks);
        SelectedLength->setObjectName(QStringLiteral("SelectedLength"));
        SelectedLength->setGeometry(QRect(570, 260, 291, 16));
        label_20 = new QLabel(CTMViewTextbooks);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(510, 320, 51, 16));
        SelectedTexbook = new QLabel(CTMViewTextbooks);
        SelectedTexbook->setObjectName(QStringLiteral("SelectedTexbook"));
        SelectedTexbook->setGeometry(QRect(570, 200, 291, 16));
        SelectedChapter = new QLabel(CTMViewTextbooks);
        SelectedChapter->setObjectName(QStringLiteral("SelectedChapter"));
        SelectedChapter->setGeometry(QRect(570, 170, 291, 16));
        SelectedPrice = new QLabel(CTMViewTextbooks);
        SelectedPrice->setObjectName(QStringLiteral("SelectedPrice"));
        SelectedPrice->setGeometry(QRect(570, 290, 291, 16));
        label_19 = new QLabel(CTMViewTextbooks);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(510, 290, 41, 16));
        label_22 = new QLabel(CTMViewTextbooks);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(510, 380, 51, 16));
        text = new QLabel(CTMViewTextbooks);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(510, 200, 61, 16));
        SelectedTitle = new QLabel(CTMViewTextbooks);
        SelectedTitle->setObjectName(QStringLiteral("SelectedTitle"));
        SelectedTitle->setGeometry(QRect(570, 140, 291, 16));
        label_16 = new QLabel(CTMViewTextbooks);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(510, 140, 51, 16));
        SelectedAuthor = new QLabel(CTMViewTextbooks);
        SelectedAuthor->setObjectName(QStringLiteral("SelectedAuthor"));
        SelectedAuthor->setGeometry(QRect(570, 320, 291, 16));
        label_23 = new QLabel(CTMViewTextbooks);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(510, 230, 51, 16));
        SelectedISBN = new QLabel(CTMViewTextbooks);
        SelectedISBN->setObjectName(QStringLiteral("SelectedISBN"));
        SelectedISBN->setGeometry(QRect(570, 350, 291, 16));
        SelectedDescription = new QTextBrowser(CTMViewTextbooks);
        SelectedDescription->setObjectName(QStringLiteral("SelectedDescription"));
        SelectedDescription->setGeometry(QRect(510, 410, 331, 161));
        SelectedDescription->setLineWidth(0);
        SelectedDescription->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label->raise();
        label_2->raise();
        widget->raise();
        line_19->raise();
        label_63->raise();
        Title->raise();
        label_3->raise();
        pushButton_3->raise();
        SelectedCourse->raise();
        SelectedType->raise();
        label_25->raise();
        label_18->raise();
        label_21->raise();
        SelectedLength->raise();
        label_20->raise();
        SelectedTexbook->raise();
        SelectedChapter->raise();
        SelectedPrice->raise();
        label_19->raise();
        label_22->raise();
        text->raise();
        SelectedTitle->raise();
        label_16->raise();
        SelectedAuthor->raise();
        label_23->raise();
        SelectedISBN->raise();
        SelectedDescription->raise();

        retranslateUi(CTMViewTextbooks);

        QMetaObject::connectSlotsByName(CTMViewTextbooks);
    } // setupUi

    void retranslateUi(QWidget *CTMViewTextbooks)
    {
        CTMViewTextbooks->setWindowTitle(QApplication::translate("CTMViewTextbooks", "Form", 0));
        label_2->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        pushButton_16->setText(QApplication::translate("CTMViewTextbooks", "Edit", 0));
        pushButton->setText(QApplication::translate("CTMViewTextbooks", "New", 0));
        NameTitle->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Item Name</span></p></body></html>", 0));
        TypeTitle->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Price</span></p></body></html>", 0));
        CourseTitle->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Type</span></p></body></html>", 0));
        label_63->setText(QApplication::translate("CTMViewTextbooks", "TeamName \302\251Copyright 2014", 0));
        label->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        Title->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_3->setText(QApplication::translate("CTMViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt;\">All Literature</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("CTMViewTextbooks", "Sign Out", 0));
        SelectedCourse->setText(QString());
        SelectedType->setText(QString());
        label_25->setText(QApplication::translate("CTMViewTextbooks", "Chapter:", 0));
        label_18->setText(QApplication::translate("CTMViewTextbooks", "Length:", 0));
        label_21->setText(QApplication::translate("CTMViewTextbooks", "ISBN:", 0));
        SelectedLength->setText(QString());
        label_20->setText(QApplication::translate("CTMViewTextbooks", "Author:", 0));
        SelectedTexbook->setText(QString());
        SelectedChapter->setText(QString());
        SelectedPrice->setText(QString());
        label_19->setText(QApplication::translate("CTMViewTextbooks", "Price:", 0));
        label_22->setText(QApplication::translate("CTMViewTextbooks", "Course:", 0));
        text->setText(QApplication::translate("CTMViewTextbooks", "Textbook:", 0));
        SelectedTitle->setText(QString());
        label_16->setText(QApplication::translate("CTMViewTextbooks", "Title:", 0));
        SelectedAuthor->setText(QString());
        label_23->setText(QApplication::translate("CTMViewTextbooks", "Type:", 0));
        SelectedISBN->setText(QString());
        SelectedDescription->setHtml(QApplication::translate("CTMViewTextbooks", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class CTMViewTextbooks: public Ui_CTMViewTextbooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTMVIEWTEXTBOOKS_H
