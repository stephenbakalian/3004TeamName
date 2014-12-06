#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>

#include "../config.h"
#include "requesthandler.h"
#include <string>
RequestHandler::RequestHandler(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketChanged(QAbstractSocket::SocketState)));
    //connect(this, SIGNAL(connection(int)), parent, SLOT(socketStatus(int)));


    //connect(this, SIGNAL(buybook(int)), parent, SLOT(socketStatus(int)));
/*
    if (parent->objectName() == "Login") {
        connect(this, SIGNAL(login(int)), parent, SLOT(loginStatus(int)));
    }
    if (parent->objectName() == "LoginWindow") {
        connect(this, SIGNAL(buybook(int)), parent, SLOT(socketStatus(int)));
    }*/
}

RequestHandler::~RequestHandler() {}

void RequestHandler::init() {
    socket->connectToHost(
        SERVER, PORT,
        QIODevice::ReadWrite,
        QAbstractSocket::AnyIPProtocol
    );
}

void RequestHandler::kill() {
    //socket->close();
    socket->disconnectFromHost();
}

void RequestHandler::AddBook(std::string bookName, double bookEdition, std::string authorName, double yearPublished, double bookPrice, std::string bookISBN){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("addbook");
    request["bookName"] = QString(bookName.c_str());
    request["bookEdition"]=(bookEdition);
    request["authorName"]=QString(authorName.c_str());
    request["yearPublished"]=(yearPublished);
    request["bookPrice"]=(bookPrice);
    request["bookISBN"]=QString(bookISBN.c_str());

    rawRequest.setObject(request);

    socket->write(rawRequest.toJson());
    socket->flush();

    /* Read from the server. */
    while (socket->waitForReadyRead()) {
        buffer = socket->readAll().trimmed();
        rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

        if (jsonError.error) {
            emit buybook(-1);
            return;
        }

        response = rawResponse.object();
        emit buybook(response["status"].toDouble());

        qDebug() << "Response status: " << response["status"].toDouble();

    }
}

void RequestHandler::AddCoruse(std::string courseCode,std::string courseInstructor,std::string courseTerm,double courseNum,std::string courseLocation){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("addcourse");
    request["courseCode"] = QString(courseCode.c_str());
    request["courseInstructor"]=QString(courseInstructor.c_str());
    request["courseTerm"]=QString(courseTerm.c_str());
    request["courseNum"]=(courseNum);
    request["courseLocation"]=QString(courseLocation.c_str());

    socket->write(rawRequest.toJson());
    socket->flush();

    /* Read from the server. */
    while (socket->waitForReadyRead()) {
        buffer = socket->readAll().trimmed();
        rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

        if (jsonError.error) {
            emit addcourse(-1);
            return;
        }

        response = rawResponse.object();
        emit addcourse(response["status"].toDouble());

        qDebug() << "Response status: " << response["status"].toDouble();
    }

}

void RequestHandler::BuyBook(std::string studentName, std::string bookISBN){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("buybook");
    request["studentName"] = QString(studentName.c_str());
    request["bookISBN"] = QString(bookISBN.c_str());
    rawRequest.setObject(request);

    socket->write(rawRequest.toJson());
    socket->flush();

    /* Read from the server. */
    while (socket->waitForReadyRead()) {
        buffer = socket->readAll().trimmed();
        rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

        if (jsonError.error) {
            emit buybook(-1);
            return;
        }

        response = rawResponse.object();
        emit buybook(response["status"].toDouble());

        qDebug() << "Response status: " << response["status"].toDouble();
    }
}

int RequestHandler::Login(std::string username) {
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("login");
    request["username"] = QString(username.c_str());
    rawRequest.setObject(request);


    double req=-10;
        socket = new QTcpSocket(this);
               socket->connectToHost(SERVER, PORT);

            if(socket->waitForConnected(3000))
            {
                //qDebug() << "Connected!";

                // send
                socket->write(rawRequest.toJson());
                socket->waitForBytesWritten(1000);
                socket->waitForReadyRead(3000);
                //qDebug() << "Reading: " << socket->bytesAvailable();

                buffer= (socket->readAll());
                //qDebug() << "Reading: " <<buffer;

                rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

                if (jsonError.error) {
                    return -2;
                }

                response = rawResponse.object();
                return (response["status"].toDouble());
                socket->close();
            }
            else
            {
                //qDebug() << "No Connecion";
                return -4;
            }
            qDebug() << req;
        return req;
}


int RequestHandler::AddToCart(std::string itemKey[], std::string username){

    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    int itemCount = 0;
    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("addToCart");

    for (int i =0; i< sizeof(itemKey); i++){
        if (!itemKey[i].empty()){
            request["items"+itemCount] = QString(itemKey[i].c_str());
            itemCount++;
            qDebug() << itemKey[i].c_str();
        }
    }
    request["itemCount"] = itemCount;
    request["user"] = QString(username.c_str());
    rawRequest.setObject(request);

    double req=-10;
    socket = new QTcpSocket(this);
    socket->connectToHost(SERVER, PORT);

    if(socket->waitForConnected(3000))
    {
        // send
                socket->write(rawRequest.toJson());
                socket->waitForBytesWritten(1000);
                socket->waitForReadyRead(3000);
                //qDebug() << "Reading: " << socket->bytesAvailable();

                buffer= (socket->readAll());
                //qDebug() << "Reading: " <<buffer;

                rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

                if (jsonError.error) {
                    return -2;
                }

                response = rawResponse.object();
                return (response["status"].toDouble());
                socket->close();
    }else{
        return -4;
    }
    qDebug() << req;
    return req;
}

void RequestHandler::socketChanged(QAbstractSocket::SocketState state) {
    switch(state) {
    case QAbstractSocket::UnconnectedState:
        emit connection(0);
        break;
    case QAbstractSocket::HostLookupState:
        emit connection(-2);
        break;
    case QAbstractSocket::ConnectingState:
        break;
    case QAbstractSocket::ConnectedState:
        emit connection(1);
        break;
    case QAbstractSocket::BoundState:
        break;
    case QAbstractSocket::ListeningState:
        break;
    case QAbstractSocket::ClosingState:
        break;
    }
}
