#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "database.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = 0);

    DataBase *getMyDB() const;
    void setMyDB(DataBase *value);

protected slots:
    void socketError();
    void socketError(QTcpSocket::SocketError error);

protected:
    void incomingConnection(qintptr socketDesc);

private:
    DataBase* myDB;
};

#endif // SERVER_H
