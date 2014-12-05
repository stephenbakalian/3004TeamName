#ifndef MODIFYTEXTBOOK_H
#define MODIFYTEXTBOOK_H
#include <QWidget>


namespace Ui {
    class ModifyTextbook;
}
class ModifyTextbook : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyTextbook(QWidget *parent = 0);
    ~ModifyTextbook();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ModifyTextbook *ui;
};

#endif // MODIFYTEXTBOOK_H
