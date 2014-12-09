/********************************************************************************
** Form generated from reading UI file 'modifytextbook.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYTEXTBOOK_H
#define UI_MODIFYTEXTBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyTextbook
{
public:
    QLabel *label_2;
    QWidget *widget;
    QLabel *label_17;
    QTextEdit *description;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *Title_2;
    QLineEdit *ISBN;
    QLineEdit *textbook;
    QComboBox *type;
    QLabel *Price;
    QLabel *label_21;
    QLabel *author_2;
    QLabel *label_18;
    QLineEdit *length;
    QLabel *label_4;
    QLineEdit *title;
    QLabel *label_22;
    QLineEdit *price;
    QLineEdit *author;
    QLabel *label_5;
    QLineEdit *chapter;
    QLabel *vourse;
    QLineEdit *course;
    QLabel *label;
    QLabel *Title;
    QLabel *label_6;
    QLabel *label_3;
    QPushButton *pushButton_3;

    void setupUi(QWidget *ModifyTextbook)
    {
        if (ModifyTextbook->objectName().isEmpty())
            ModifyTextbook->setObjectName(QStringLiteral("ModifyTextbook"));
        ModifyTextbook->resize(862, 694);
        label_2 = new QLabel(ModifyTextbook);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 0, 461, 71));
        widget = new QWidget(ModifyTextbook);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(9, 80, 851, 531));
        label_17 = new QLabel(widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(430, 120, 181, 31));
        description = new QTextEdit(widget);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(430, 160, 381, 271));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 440, 191, 27));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(430, 440, 181, 27));
        gridLayoutWidget = new QWidget(widget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(50, 120, 331, 361));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Title_2 = new QLabel(gridLayoutWidget);
        Title_2->setObjectName(QStringLiteral("Title_2"));

        gridLayout->addWidget(Title_2, 1, 0, 1, 1);

        ISBN = new QLineEdit(gridLayoutWidget);
        ISBN->setObjectName(QStringLiteral("ISBN"));
        ISBN->setPlaceholderText(QStringLiteral(""));
        ISBN->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(ISBN, 5, 1, 1, 1);

        textbook = new QLineEdit(gridLayoutWidget);
        textbook->setObjectName(QStringLiteral("textbook"));
        textbook->setEnabled(false);
        textbook->setAutoFillBackground(false);
        textbook->setDragEnabled(false);
        textbook->setPlaceholderText(QStringLiteral(""));
        textbook->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(textbook, 7, 1, 1, 1);

        type = new QComboBox(gridLayoutWidget);
        type->setObjectName(QStringLiteral("type"));
        type->setEditable(false);

        gridLayout->addWidget(type, 0, 1, 1, 1);

        Price = new QLabel(gridLayoutWidget);
        Price->setObjectName(QStringLiteral("Price"));

        gridLayout->addWidget(Price, 2, 0, 1, 1);

        label_21 = new QLabel(gridLayoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 5, 0, 1, 1);

        author_2 = new QLabel(gridLayoutWidget);
        author_2->setObjectName(QStringLiteral("author_2"));

        gridLayout->addWidget(author_2, 3, 0, 1, 1);

        label_18 = new QLabel(gridLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 4, 0, 1, 1);

        length = new QLineEdit(gridLayoutWidget);
        length->setObjectName(QStringLiteral("length"));
        length->setPlaceholderText(QStringLiteral(""));
        length->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(length, 4, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        title = new QLineEdit(gridLayoutWidget);
        title->setObjectName(QStringLiteral("title"));
        title->setPlaceholderText(QStringLiteral(""));
        title->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(title, 1, 1, 1, 1);

        label_22 = new QLabel(gridLayoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout->addWidget(label_22, 0, 0, 1, 1);

        price = new QLineEdit(gridLayoutWidget);
        price->setObjectName(QStringLiteral("price"));
        price->setPlaceholderText(QStringLiteral(""));
        price->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(price, 2, 1, 1, 1);

        author = new QLineEdit(gridLayoutWidget);
        author->setObjectName(QStringLiteral("author"));
        author->setPlaceholderText(QStringLiteral(""));
        author->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(author, 3, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 8, 0, 1, 1);

        chapter = new QLineEdit(gridLayoutWidget);
        chapter->setObjectName(QStringLiteral("chapter"));
        chapter->setEnabled(false);
        chapter->setPlaceholderText(QStringLiteral(""));
        chapter->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(chapter, 8, 1, 1, 1);

        vourse = new QLabel(gridLayoutWidget);
        vourse->setObjectName(QStringLiteral("vourse"));

        gridLayout->addWidget(vourse, 6, 0, 1, 1);

        course = new QLineEdit(gridLayoutWidget);
        course->setObjectName(QStringLiteral("course"));
        course->setPlaceholderText(QStringLiteral(""));
        course->setCursorMoveStyle(Qt::LogicalMoveStyle);

        gridLayout->addWidget(course, 6, 1, 1, 1);

        label = new QLabel(ModifyTextbook);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 871, 701));
        Title = new QLabel(ModifyTextbook);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(70, 0, 1051, 71));
        Title->setFrameShape(QFrame::Box);
        Title->setLineWidth(0);
        label_6 = new QLabel(ModifyTextbook);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(350, 660, 181, 31));
        label_3 = new QLabel(ModifyTextbook);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 70, 491, 91));
        label_3->setFrameShape(QFrame::NoFrame);
        pushButton_3 = new QPushButton(ModifyTextbook);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(750, 90, 88, 27));
        label->raise();
        widget->raise();
        label_6->raise();
        Title->raise();
        label_2->raise();
        label_3->raise();
        pushButton_3->raise();

        retranslateUi(ModifyTextbook);

        QMetaObject::connectSlotsByName(ModifyTextbook);
    } // setupUi

    void retranslateUi(QWidget *ModifyTextbook)
    {
        ModifyTextbook->setWindowTitle(QApplication::translate("ModifyTextbook", "Form", 0));
        label_2->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:24pt; color:#f5f5f5;\">Textbook Purchasing System</span></p></body></html>", 0));
        label_17->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Description:</span></p></body></html>", 0));
        description->setHtml(QApplication::translate("ModifyTextbook", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Chapter and textbook feild are disabled/endabled on the type selcted</p></body></html>", 0));
        pushButton_2->setText(QApplication::translate("ModifyTextbook", "Cancel ", 0));
        pushButton->setText(QApplication::translate("ModifyTextbook", "Confirm", 0));
        Title_2->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Title:</span></p></body></html>", 0));
        ISBN->setText(QString());
        textbook->setText(QString());
        type->clear();
        type->insertItems(0, QStringList()
         << QApplication::translate("ModifyTextbook", "Textbook", 0)
         << QApplication::translate("ModifyTextbook", "Chapter", 0)
         << QApplication::translate("ModifyTextbook", "Section", 0)
        );
        Price->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Price:</span></p></body></html>", 0));
        label_21->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">ISBN:</span></p></body></html>", 0));
        author_2->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Author:</span></p></body></html>", 0));
        label_18->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Length:</span></p></body></html>", 0));
        length->setText(QString());
        label_4->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Textbook:</span></p></body></html>", 0));
        title->setText(QString());
        label_22->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Type:</span></p></body></html>", 0));
        price->setText(QString());
        author->setText(QString());
        label_5->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Chapter:</span></p></body></html>", 0));
        chapter->setText(QString());
        vourse->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:16pt;\">Course:</span></p></body></html>", 0));
        course->setText(QString());
        label->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><img src=\":/new/prefix1/Background.png\"/></p></body></html>", 0));
        Title->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:24pt; color:#f8f8f8;\">Carleton University </span></p></body></html>", 0));
        label_6->setText(QApplication::translate("ModifyTextbook", "TeamName \302\251Copyright 2014", 0));
        label_3->setText(QApplication::translate("ModifyTextbook", "<html><head/><body><p><span style=\" font-size:24pt;\">Textbook Information</span></p></body></html>", 0));
        pushButton_3->setText(QApplication::translate("ModifyTextbook", "Sign Out", 0));
    } // retranslateUi

};

namespace Ui {
    class ModifyTextbook: public Ui_ModifyTextbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYTEXTBOOK_H
