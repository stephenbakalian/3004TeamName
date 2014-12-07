#ifndef ERROR_H
#define ERROR_H

#include <QWidget>

namespace Ui {
class Error;
}

class Error : public QWidget
{
    Q_OBJECT

public:
    explicit Error(QWidget *parent = 0);
    void setError(QString, int);
    ~Error();
    void setUsername(std::string username);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Error *ui;
    QString errorMessage;
    int errorPage;
    std::string username;
};

#endif // ERROR_H
