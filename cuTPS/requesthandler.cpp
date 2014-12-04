#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>

#include "../config.h"
#include "requesthandler.h"

RequestHandler::RequestHandler(QObject *parent) :
    QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketChanged(QAbstractSocket::SocketState)));
    connect(this, SIGNAL(connection(int)), parent, SLOT(socketStatus(int)));


    //connect(this, SIGNAL(buybook(int)), parent, SLOT(socketStatus(int)));

    if (parent->objectName() == "LoginWindow") {
        connect(this, SIGNAL(login(int)), parent, SLOT(loginStatus(int)));
    }
    if (parent->objectName() == "LoginWindow") {
        connect(this, SIGNAL(buybook(int)), parent, SLOT(socketStatus(int)));
    }
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

void RequestHandler::Login(std::string username) {
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

    socket->write(rawRequest.toJson());
    socket->flush();

    /* Read from the server. */
    while (socket->waitForReadyRead()) {
        buffer = socket->readAll().trimmed();
        rawResponse = QJsonDocument::fromJson(buffer, &jsonError);

        if (jsonError.error) {
            emit login(-1);
            kill();
            return;
        }

        response = rawResponse.object();
        emit login(response["status"].toDouble());

        qDebug() << "Response status: " << response["status"].toDouble();
    }
    kill();
}

void RequestHandler::socketChanged(QAbstractSocket::SocketState state) {
    switch(state) {
    case QAbstractSocket::UnconnectedState:
        emit connection(0);
        break;
    case QAbstractSocket::HostLookupState:
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
