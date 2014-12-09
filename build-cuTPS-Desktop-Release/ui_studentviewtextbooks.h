/********************************************************************************
** Form generated from reading UI file 'studentviewtextbooks.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTVIEWTEXTBOOKS_H
#define UI_STUDENTVIEWTEXTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
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

class Ui_StudentViewTextbooks
{
public:
    QLabel *label_2;
    QWidget *widget;
    QLabel *label_19;
    QTextBrowser *SelectedDescription;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *SelectedTitle;
    QLabel *SelectedLength;
    QLabel *SelectedPrice;
    QLabel *text;
    QLabel *SelectedISBN;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QCheckBox *checkBox;
    QFrame *line;
    QLabel *label_22;
    QLabel *SelectedCourse;
    QLabel *SelectedType;
    QLabel *label_23;
    QLabel *SelectedChapter;
    QLabel *label_25;
    QLabel *SelectedAuthor;
    QLabel *SelectedTexbook;
    QPushButton *pushButton_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label;
    QLabel *Title;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_16;
    QLabel *label_18;
    QFrame *line_7;
    QPushButton *pushButton_6;

    void setupUi(QWidget *StudentViewTextbooks)
    {
        if (StudentViewTextbooks->objectName().isEmpty())
            StudentViewTextbooks->setObjectName(QStringLiteral("StudentViewTextbooks"));
        StudentViewTextbooks->resize(863, 694);
        label_2 = new QLabel(StudentViewTextbooks);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        label_2->setLineWidth(0);
        widget = new QWidget(StudentViewTextbooks);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 80, 851, 531));
        label_19 = new QLabel(widget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(500, 210, 41, 16));
        SelectedDescription = new QTextBrowser(widget);
        SelectedDescription->setObjectName(QStringLiteral("SelectedDescription"));
        SelectedDescription->setGeometry(QRect(500, 330, 331, 161));
        SelectedDescription->setLineWidth(0);
        SelectedDescription->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        label_20 = new QLabel(widget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(500, 240, 51, 16));
        label_21 = new QLabel(widget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(500, 270, 41, 16));
        SelectedTitle = new QLabel(widget);
        SelectedTitle->setObjectName(QStringLiteral("SelectedTitle"));
        SelectedTitle->setGeometry(QRect(560, 60, 291, 16));
        SelectedLength = new QLabel(widget);
        SelectedLength->setObjectName(QStringLiteral("SelectedLength"));
        SelectedLength->setGeometry(QRect(560, 180, 291, 16));
        SelectedPrice = new QLabel(widget);
        SelectedPrice->setObjectName(QStringLiteral("SelectedPrice"));
        SelectedPrice->setGeometry(QRect(560, 210, 291, 16));
        text = new QLabel(widget);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(500, 120, 291, 16));
        SelectedISBN = new QLabel(widget);
        SelectedISBN->setObjectName(QStringLiteral("SelectedISBN"));
        SelectedISBN->setGeometry(QRect(560, 270, 291, 16));
        pushButton_7 = new QPushButton(widget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(740, 500, 88, 27));
        pushButton_8 = new QPushButton(widget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(520, 500, 171, 27));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(920, 140, 89, 21));
        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(480, 80, 20, 401));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(500, 300, 51, 16));
        SelectedCourse = new QLabel(widget);
        SelectedCourse->setObjectName(QStringLiteral("SelectedCourse"));
        SelectedCourse->setGeometry(QRect(560, 300, 290, 16));
        SelectedType = new QLabel(widget);
        SelectedType->setObjectName(QStringLiteral("SelectedType"));
        SelectedType->setGeometry(QRect(560, 150, 291, 16));
        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(500, 150, 51, 16));
        SelectedChapter = new QLabel(widget);
        SelectedChapter->setObjectName(QStringLiteral("SelectedChapter"));
        SelectedChapter->setGeometry(QRect(560, 90, 291, 16));
        label_25 = new QLabel(widget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(500, 90, 51, 16));
        SelectedAuthor = new QLabel(widget);
        SelectedAuthor->setObjectName(QStringLiteral("SelectedAuthor"));
        SelectedAuthor->setGeometry(QRect(560, 240, 291, 16));
        SelectedTexbook = new QLabel(widget);
        SelectedTexbook->setObjectName(QStringLiteral("SelectedTexbook"));
        SelectedTexbook->setGeometry(QRect(560, 120, 291, 16));
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(20, 500, 459, 27));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(20, 70, 451, 401));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea::add-page:horizontal, QScrollArea::sub-page:horizontal {\n"
"    background: none;\n"
"}"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 451, 401));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 399));
        verticalLayoutWidget = new QWidget(scrollAreaWidgetContents);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 431, 391));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_13 = new QLabel(verticalLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 0, 0, 1, 1);

        label_17 = new QLabel(verticalLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 0, 1, 1, 1);

        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 0, 3, 1, 1);

        label_15 = new QLabel(verticalLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFrameShadow(QFrame::Plain);
        label_15->setLineWidth(0);

        gridLayout->addWidget(label_15, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(StudentViewTextbooks);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        Title = new QLabel(StudentViewTextbooks);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_6 = new QLabel(StudentViewTextbooks);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label_3 = new QLabel(StudentViewTextbooks);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 521, 81));
        label_16 = new QLabel(StudentViewTextbooks);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(500, 140, 51, 16));
        label_18 = new QLabel(StudentViewTextbooks);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(500, 260, 51, 16));
        line_7 = new QFrame(StudentViewTextbooks);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(870, 430, 3, 27));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        pushButton_6 = new QPushButton(StudentViewTextbooks);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(750, 90, 88, 27));
        label->raise();
        widget->raise();
        Title->raise();
        label_6->raise();
        label_3->raise();
        label_2->raise();
        label_16->raise();
        label_18->raise();
        line_7->raise();
        pushButton_6->raise();

        retranslateUi(StudentViewTextbooks);

        QMetaObject::connectSlotsByName(StudentViewTextbooks);
    } // setupUi

    void retranslateUi(QWidget *StudentViewTextbooks)
    {
        StudentViewTextbooks->setWindowTitle(QApplication::translate("StudentViewTextbooks", "Form", 0));
        label_2->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        label_19->setText(QApplication::translate("StudentViewTextbooks", "Price:", 0));
        SelectedDescription->setHtml(QApplication::translate("StudentViewTextbooks", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_20->setText(QApplication::translate("StudentViewTextbooks", "Author:", 0));
        label_21->setText(QApplication::translate("StudentViewTextbooks", "ISBN:", 0));
        SelectedTitle->setText(QString());
        SelectedLength->setText(QString());
        SelectedPrice->setText(QString());
        text->setText(QApplication::translate("StudentViewTextbooks", "Textbook:", 0));
        SelectedISBN->setText(QString());
        pushButton_7->setText(QApplication::translate("StudentViewTextbooks", "View Cart", 0));
        pushButton_8->setText(QApplication::translate("StudentViewTextbooks", "View Owned Items", 0));
        checkBox->setText(QApplication::translate("StudentViewTextbooks", "CheckBox", 0));
        label_22->setText(QApplication::translate("StudentViewTextbooks", "Course:", 0));
        SelectedCourse->setText(QString());
        SelectedType->setText(QString());
        label_23->setText(QApplication::translate("StudentViewTextbooks", "Type:", 0));
        SelectedChapter->setText(QString());
        label_25->setText(QApplication::translate("StudentViewTextbooks", "Chapter:", 0));
        SelectedAuthor->setText(QString());
        SelectedTexbook->setText(QString());
        pushButton_5->setText(QApplication::translate("StudentViewTextbooks", "Add Selected items to Cart", 0));
        label_13->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Item Name</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Type</span></p></body></html>", 0));
        label_14->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Select</span></p></body></html>", 0));
        label_15->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-weight:600; text-decoration: underline;\">Price</span></p></body></html>", 0));
        label->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        Title->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("StudentViewTextbooks", "TeamName \302\251Copyright 2014", 0));
        label_3->setText(QApplication::translate("StudentViewTextbooks", "<html><head/><body><p><span style=\" font-size:24pt;\">My Required Literature</span></p></body></html>", 0));
        label_16->setText(QApplication::translate("StudentViewTextbooks", "Title:", 0));
        label_18->setText(QApplication::translate("StudentViewTextbooks", "Length:", 0));
        pushButton_6->setText(QApplication::translate("StudentViewTextbooks", "Sign Out", 0));
    } // retranslateUi

};

namespace Ui {
    class StudentViewTextbooks: public Ui_StudentViewTextbooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTVIEWTEXTBOOKS_H
