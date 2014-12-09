#ifndef STUDENTVIEWTEXTBOOKS_H
#define STUDENTVIEWTEXTBOOKS_H

#include <QWidget>
#include "item.h"
#include "requesthandler.h"
#include "section.h"
#include "chapter.h"
#include <QSignalMapper>
#include <QCheckBox>
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
    void showItems(QList<Item> list);
    void setUsername(std::string username);
    //void showDetails(int);

private slots:
    void showDetails(int);

    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_5_clicked();
private:
    Ui::StudentViewTextbooks *ui;
    std::string username;
    void updateUI();
    QList<Item> items;
    QList<QSignalMapper*> mapper;
    QList<QCheckBox*> addToCart;


};

#endif // STUDENTVIEWTEXTBOOKS_H
