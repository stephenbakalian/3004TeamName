#ifndef STUDENTVIEWTEXTBOOKS_H
#define STUDENTVIEWTEXTBOOKS_H

#include <QWidget>

#include "requesthandler.h"

namespace Ui {
class StudentViewTextbooks;
}

class StudentViewTextbooks : public QWidget
{
    Q_OBJECT

public:
    RequestHandler *reqHandler;
    explicit StudentViewTextbooks(QWidget *parent = 0);
    ~StudentViewTextbooks();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::StudentViewTextbooks *ui;
};

#endif // STUDENTVIEWTEXTBOOKS_H
