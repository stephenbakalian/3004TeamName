#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

#include <QThread>
#include <QTcpSocket>
#include "database.h"

bool addBook(std::string, int, std::string, int, double, std::string);
bool addCourse(std::string, std::string, std::string, int, std::string);
void selectCourses();
void selectBooks();
bool addChapter(int, int, double, std::string, std::string);
bool addSection(int, int, double, std::string, std::string);

class Connection : public QThread
{
    Q_OBJECT
public:
    Connection(QObject *parent = 0, int socketDesc = -1);
    void run();

protected:
    void startDB();


signals:
    void error(QTcpSocket::SocketError socketError);
    void error();

private:
    int socketDesc;
    DataBase* myDB;
    std::string concatStrInt(std::string str, int num);
};

#endif // CONNECTION_H
