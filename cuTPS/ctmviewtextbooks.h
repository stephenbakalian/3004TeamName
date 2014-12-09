#ifndef CTMVIEWTEXTBOOKS_H
#define CTMVIEWTEXTBOOKS_H
#include <item.h>
#include <QWidget>
#include <QSignalMapper>
namespace Ui {
class CTMViewTextbooks;
}

class CTMViewTextbooks : public QWidget
{
    Q_OBJECT

public:
    explicit CTMViewTextbooks(QWidget *parent = 0);
    ~CTMViewTextbooks();
    void setUsername(std::string username);
    void showItems(QList<Item> list);
    void showDetails(int);
private slots:
    void on_pushButton_16_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::CTMViewTextbooks *ui;
    std::string username;
    QList<QSignalMapper*> mapper;

};

#endif // CTMVIEWTEXTBOOKS_H
