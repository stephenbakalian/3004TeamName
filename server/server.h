#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    explicit Server(QObject *parent = 0);

protected slots:
    void socketError();
    void socketError(QTcpSocket::SocketError error);

protected:
    void incomingConnection(qintptr socketDesc);

};

#endif // SERVER_H
