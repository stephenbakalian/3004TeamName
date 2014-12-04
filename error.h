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
    ~Error();

private:
    Ui::Error *ui;
};

#endif // ERROR_H
