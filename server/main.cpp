#include <QCoreApplication>
#include <QDebug>

#include <string>

#include "../config.h"
#include "server.h"
#include "database.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    DataBase* myDB = new DataBase;
    Server *server = new Server(0);
    server->setMyDB(myDB);
    if (server->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Server started.";
        qDebug() << "Listening on port: " << server->serverPort();
    } else {
        qDebug() << "There was an error starting the server.";
    }

    a.connect(server, SIGNAL(destroyed()), server, SLOT(deleteLater()));
    return a.exec();
}




