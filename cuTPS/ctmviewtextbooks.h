#ifndef CTMVIEWTEXTBOOKS_H
#define CTMVIEWTEXTBOOKS_H
#include <item.h>
#include <QWidget>
#include <QSignalMapper>

#include "item.h"
#include "requesthandler.h"
#include "section.h"
#include "chapter.h"

namespace Ui {
class CTMViewTextbooks;
}

class CTMViewTextbooks : public QWidget
{
    Q_OBJECT

public:
    RequestHandler *reqHandler;
    explicit CTMViewTextbooks(QWidget *parent = 0);
    ~CTMViewTextbooks();
    void setUsername(std::string username);
    void showItems(QList<Item> list);
private slots:
    void on_pushButton_16_clicked();
    void showDetails(int);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::CTMViewTextbooks *ui;
    std::string username;
    QList<QSignalMapper*> mapper;
    void updateUI();
    QList<Item> items;
};

#endif // CTMVIEWTEXTBOOKS_H
