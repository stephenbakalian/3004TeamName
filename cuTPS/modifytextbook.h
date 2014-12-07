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
    void setData(QString*);
    ~ModifyTextbook();
    void setUsername(std::string username);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_type_currentIndexChanged(const QString &arg1);

    void on_type_activated(int index);

private:
    Ui::ModifyTextbook *ui;
    void updateAvailableFeilds();
    std::string username;
};

#endif // MODIFYTEXTBOOK_H
