#ifndef OWNEDBOOKS_H
#define OWNEDBOOKS_H

#include <QWidget>

namespace Ui {
class OwnedBooks;
}

class OwnedBooks : public QWidget
{
    Q_OBJECT

public:
    explicit OwnedBooks(QWidget *parent = 0);
    ~OwnedBooks();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::OwnedBooks *ui;
};

#endif // OWNEDBOOKS_H
