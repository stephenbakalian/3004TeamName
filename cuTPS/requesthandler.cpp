#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>
#include <iostream>
#include <sstream>

#include "../config.h"
#include "requesthandler.h"


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

int RequestHandler::AddToCart(QList<Item> items, std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    int itemCount = 0;
    Item bookList[items.size()];

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("addToCart");


    for (int i =0; i < items.size(); i++){
        bookList[i] = items.value(i);
    }
    qDebug() << items.size();
    for (int i =0; i< items.size(); i++){
        request[concatStrInt("title",i).c_str()]   = QString(bookList[i].getTitle().c_str());
        request[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
        request[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
        request[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
        request[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
        request[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
        request[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
        itemCount++;
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

QList<Item> RequestHandler::booksOwned(std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    QList<Item> ownedBooks;
    int itemCount;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("booksOwned");
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
            return ownedBooks;//-2 error
        }

        response = rawResponse.object();

        itemCount=response["itemCount"].toDouble();

        qDebug() << itemCount;
        for (int i = 0; i < itemCount; i++){

            //ownedBooks.insert(i, response["items"+i]);

            Item item;
            item.setAuthor(response[concatStrInt("author",i).c_str()].toString().toStdString());
            item.setCourse(response[concatStrInt("course",i).c_str()].toString().toStdString());
            item.setDescription(response[concatStrInt("description",i).c_str()].toString().toStdString());
            item.setPrice(response[concatStrInt("price",i).c_str()].toString().toStdString());
            item.setPurchaseDate(response[concatStrInt("purchasedate",i).c_str()].toString().toStdString());
            item.setTitle(response[concatStrInt("title",i).c_str()].toString().toStdString());
            item.setType(response[concatStrInt("type",itemCount).c_str()].toString().toStdString());
            ownedBooks.push_back(item);
            qDebug() << ownedBooks.value(i).getTitle().c_str();
        }
        return ownedBooks;
        socket->close();
    }else{
        return ownedBooks;//-4 error
    }

    qDebug() << req;

    return ownedBooks;
}

QList<Item> RequestHandler::viewCart(std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    QList<Item> ownedBooks;
    int itemCount;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("viewCart");
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
            return ownedBooks;//-2 error
        }

        response = rawResponse.object();
        qDebug()<< rawResponse.toVariant().toString();
        qDebug()<< rawResponse;
        itemCount=response["itemCount"].toDouble();

        qDebug() << itemCount;
        for (int i = 0; i < itemCount; i++){
            Item item;
            item.setAuthor(response[concatStrInt("author",i).c_str()].toString().toStdString());
            item.setCourse(response[concatStrInt("course",i).c_str()].toString().toStdString());
            item.setDescription(response[concatStrInt("description",i).c_str()].toString().toStdString());
            item.setPrice(response[concatStrInt("price",i).c_str()].toString().toStdString());
            item.setPurchaseDate(response[concatStrInt("purchasedate",i).c_str()].toString().toStdString());
            item.setTitle(response[concatStrInt("title",i).c_str()].toString().toStdString());
            item.setType(response[concatStrInt("type",i).c_str()].toString().toStdString());
            ownedBooks.push_back(item);
            qDebug() << ownedBooks.value(i).getTitle().c_str();
        }
        return ownedBooks;
        socket->close();
    }else{
        return ownedBooks;//-4 error
    }

    qDebug() << req;

    return ownedBooks;
}

int RequestHandler::checkout(QList<Item> cartItems, std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    int itemCount   = 0;
    Item bookList[cartItems.size()];

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("checkout");
    request["username"] = QString(username.c_str());

    for (int i =0; i < cartItems.size(); i++){
        bookList[i] = cartItems.value(i);
    }
    qDebug() << cartItems.size();
    for (int i =0; i< cartItems.size(); i++){
        request[concatStrInt("title",i).c_str()]   = QString(bookList[i].getTitle().c_str());
        request[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
        request[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
        request[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
        request[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
        request[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
        request[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
        itemCount++;
    }
    qDebug() << itemCount;
    request["itemCount"] = itemCount;
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

int RequestHandler::addItem(Item item){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("addItem");
    request["title"]         = QString(item.getTitle().c_str());
    request["author"]        = QString(item.getAuthor().c_str());
    request["description"]   = QString(item.getDescription().c_str());
    request["course"]        = QString(item.getCourse().c_str());
    request["purchasedate"]  = QString(item.getPurchaseDate().c_str());
    request["price"]         = QString(item.getPrice().c_str());
    request["type"]          = QString(item.getType().c_str());
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

QList<Item> RequestHandler::getStuCourseLoad(std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    QList<Item> ownedBooks;
    int itemCount;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("StuCourseLoad");
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
            return ownedBooks;//-2 error
        }

        response = rawResponse.object();
        qDebug()<< rawResponse.toVariant().toString();
        qDebug()<< rawResponse;
        itemCount=response["itemCount"].toDouble();

        qDebug() << itemCount;
        for (int i = 0; i < itemCount; i++){
            Item item;
            item.setAuthor(response[concatStrInt("author",i).c_str()].toString().toStdString());
            item.setCourse(response[concatStrInt("course",i).c_str()].toString().toStdString());
            item.setDescription(response[concatStrInt("description",i).c_str()].toString().toStdString());
            item.setPrice(response[concatStrInt("price",i).c_str()].toString().toStdString());
            item.setPurchaseDate(response[concatStrInt("purchasedate",i).c_str()].toString().toStdString());
            item.setTitle(response[concatStrInt("title",i).c_str()].toString().toStdString());
            item.setType(response[concatStrInt("type",i).c_str()].toString().toStdString());
            ownedBooks.push_back(item);
            qDebug() << ownedBooks.value(i).getTitle().c_str();
        }
        return ownedBooks;
        socket->close();
    }else{
        return ownedBooks;//-4 error
    }

    qDebug() << req;

    return ownedBooks;
}

QList<Item> RequestHandler::getAllItems(){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;
    QList<Item> ownedBooks;
    int itemCount;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("allItem");
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
            return ownedBooks;//-2 error
        }

        response = rawResponse.object();
        qDebug()<< rawResponse.toVariant().toString();
        qDebug()<< rawResponse;
        itemCount=response["itemCount"].toDouble();

        qDebug() << itemCount;
        for (int i = 0; i < itemCount; i++){
            Item item;
            item.setAuthor(response[concatStrInt("author",i).c_str()].toString().toStdString());
            item.setCourse(response[concatStrInt("course",i).c_str()].toString().toStdString());
            item.setDescription(response[concatStrInt("description",i).c_str()].toString().toStdString());
            item.setPrice(response[concatStrInt("price",i).c_str()].toString().toStdString());
            item.setPurchaseDate(response[concatStrInt("purchasedate",i).c_str()].toString().toStdString());
            item.setTitle(response[concatStrInt("title",i).c_str()].toString().toStdString());
            item.setType(response[concatStrInt("type",i).c_str()].toString().toStdString());
            ownedBooks.push_back(item);
            qDebug() << ownedBooks.value(i).getTitle().c_str();
        }
        return ownedBooks;
        socket->close();
    }else{
        return ownedBooks;//-4 error
    }

    qDebug() << req;

    return ownedBooks;
}

int RequestHandler::emptyCart(std::string username){
    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
    QJsonParseError jsonError;

    /* Connect to the server. */
    init();

    /* Generate the request object. */
    request["request"] = QString("emptyCart");
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

std::string RequestHandler::concatStrInt(std::string str, int num){
    std::stringstream test;
    test << str << num;
    return test.str();
}
