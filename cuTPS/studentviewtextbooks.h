#ifndef STUDENTVIEWTEXTBOOKS_H
#define STUDENTVIEWTEXTBOOKS_H

#include <QWidget>

namespace Ui {
class StudentViewTextbooks;
}

class StudentViewTextbooks : public QWidget
{
    Q_OBJECT

public:
    explicit StudentViewTextbooks(QWidget *parent = 0);
    ~StudentViewTextbooks();

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::StudentViewTextbooks *ui;
};

#endif // STUDENTVIEWTEXTBOOKS_H
