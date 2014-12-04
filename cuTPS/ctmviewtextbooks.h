#ifndef CTMVIEWTEXTBOOKS_H
#define CTMVIEWTEXTBOOKS_H

#include <QWidget>

namespace Ui {
class CTMViewTextbooks;
}

class CTMViewTextbooks : public QWidget
{
    Q_OBJECT

public:
    explicit CTMViewTextbooks(QWidget *parent = 0);
    ~CTMViewTextbooks();

private slots:
    void on_pushButton_16_clicked();

private:
    Ui::CTMViewTextbooks *ui;
};

#endif // CTMVIEWTEXTBOOKS_H
