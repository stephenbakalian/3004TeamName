#include <QDebug>

#include "server.h"
#include "connection.h"

Server::Server(QObject *parent) :
    QTcpServer(parent)
{

}

void Server::incomingConnection(qintptr socketDesc) {

    qDebug() << "There is an incomming connection.";

    Connection *conn = new Connection(this, socketDesc);
    connect(conn, SIGNAL(finished()), conn, SLOT(deleteLater()));
    connect(conn, SIGNAL(error(QTcpSocket::SocketError)), this, SLOT(socketError(QTcpSocket::SocketError)));
    connect(conn, SIGNAL(error()), this, SLOT(socketError()));
    conn->setMyDB(myDB);
    conn->start();
}
DataBase *Server::getMyDB() const
{
    return myDB;
}

void Server::setMyDB(DataBase *value)
{
    myDB = value;
}


void Server::socketError(QTcpSocket::SocketError error) {
    socketError();
}

void Server::socketError() {
    qDebug() << "There was an error with the connection.";
}
