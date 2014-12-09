#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>
#include <QList>
#include <iostream>
#include <sstream>

#include "connection.h"
#include "sharedmanager.h"
#include "studentmanager.h"
#include "ctmmanager.h"
#include "item.h"

Connection::Connection(QObject *parent, int socketDesc) :
QThread(parent) {
// Connect to the database
this->socketDesc = socketDesc;
// ***** END OF DATABASE TESTING *****
}

void Connection::run() {
    QTcpSocket socket;

    if (!socket.setSocketDescriptor(socketDesc)) {
        emit error(socket.error());
        return;
    }

    QByteArray      buffer;
    QJsonDocument   rawRequest;
    QJsonObject     request;
    QJsonDocument   rawResponse;
    QJsonObject     response;
    QJsonParseError jsonError;

    while (socket.waitForReadyRead()) {
        buffer = socket.readAll().trimmed();
        rawRequest = QJsonDocument::fromJson(buffer, &jsonError);

        if (jsonError.error) {
            qDebug() << "Error: " << jsonError.errorString();
            continue;
        }

        request = rawRequest.object();

        if (request["request"] == QString("login")) {

            std::string username    = request["username"].toString().toStdString();
            response["status"] = SharedManager().loginHandler(username);

        } else if (request["request"] == QString("addToCart")){
            QList<Item> addToCarItems;
            int         itemCount   = request["itemCount"].toDouble();
            std::string user        = request["user"].toString().toStdString();

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
                item.setISBN(response[concatStrInt("isbn",i).c_str()].toString().toStdString());
                item.setLength(response[concatStrInt("length",i).c_str()].toString().toStdString());
                addToCarItems.push_back(item);
                qDebug() << addToCarItems.value(i).getTitle().c_str();
            }

            response["status"] = StudentManager().addToCart(user, addToCarItems, myDB);
        } else if (request["request"] == QString("booksOwned")){

            qDebug() << "owned books request made";
            std::string user        = request["user"].toString().toStdString();
            QList<Item> ownedBooks  = StudentManager().viewPurchasedItems(user);
            int         itemCount   = 0;

            Item bookList[ownedBooks.size()];

            for (int i =0; i < ownedBooks.size(); i++){
                bookList[i] = ownedBooks.value(i);
            }
            qDebug() << ownedBooks.size();
            for (int i =0; i< ownedBooks.size(); i++){
                response[concatStrInt("title",itemCount).c_str()]         = QString(bookList[i].getTitle().c_str());
                response[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
                response[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
                response[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
                response[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
                response[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
                response[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
                response[concatStrInt("isbn",itemCount).c_str()]          = QString(bookList[i].getISBN().c_str());
                response[concatStrInt("length",itemCount).c_str()]        = QString(bookList[i].getLength().c_str());
                itemCount++;
            //    qDebug() << bookList[i];
            }

            response["itemCount"] = itemCount;

        } else if (request["request"] == QString("viewCart")){

            qDebug() << "view cart request made";
            std::string user        = request["user"].toString().toStdString();
            QList<Item> ownedBooks  = StudentManager().viewCart(user, myDB);
            int         itemCount   = 0;

            Item bookList[ownedBooks.size()];

            for (int i =0; i < ownedBooks.size(); i++){
                bookList[i] = ownedBooks.value(i);
            }
            qDebug() << ownedBooks.size();
            for (int i =0; i< ownedBooks.size(); i++){
                response[concatStrInt("title",itemCount).c_str()]         = QString(bookList[i].getTitle().c_str());
                response[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
                response[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
                response[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
                response[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
                response[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
                response[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
                response[concatStrInt("isbn",itemCount).c_str()]         = QString(bookList[i].getISBN().c_str());
                response[concatStrInt("length",itemCount).c_str()]          = QString(bookList[i].getLength().c_str());
                itemCount++;
                qDebug() << bookList[i].getTitle().c_str();
            }

            response["itemCount"] = itemCount;

        } else if (request["request"] == QString("StuCourseLoad")){

            qDebug() << "student course load request made";
            std::string user        = request["user"].toString().toStdString();

            QList<Course> regCourse = StudentManager().getEnrolledCourse(user);

            QList<Item> ownedBooks  = StudentManager().getBooksFromCourse(regCourse, myDB);
            int         itemCount   = 0;

            Item bookList[ownedBooks.size()];

            for (int i =0; i < ownedBooks.size(); i++){
                bookList[i] = ownedBooks.value(i);
            }
            qDebug() << ownedBooks.size();
            for (int i =0; i< ownedBooks.size(); i++){
                response[concatStrInt("title",itemCount).c_str()]         = QString(bookList[i].getTitle().c_str());
                response[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
                response[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
                response[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
                response[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
                response[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
                response[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
                response[concatStrInt("isbn",itemCount).c_str()]         = QString(bookList[i].getISBN().c_str());
                response[concatStrInt("length",itemCount).c_str()]          = QString(bookList[i].getLength().c_str());
                itemCount++;
                qDebug() << bookList[i].getTitle().c_str();
            }

            response["itemCount"] = itemCount;
        } else if (request["request"] == QString("allItem")){

            qDebug() << "all course request made";

            QList<Item> ownedBooks  = CTMManager().getAllItems(myDB);
            int         itemCount   = 0;

            Item bookList[ownedBooks.size()];

            for (int i =0; i < ownedBooks.size(); i++){
                bookList[i] = ownedBooks.value(i);
            }
            qDebug() << ownedBooks.size();
            for (int i =0; i< ownedBooks.size(); i++){
                response[concatStrInt("title",itemCount).c_str()]         = QString(bookList[i].getTitle().c_str());
                response[concatStrInt("author",itemCount).c_str()]        = QString(bookList[i].getAuthor().c_str());
                response[concatStrInt("description",itemCount).c_str()]   = QString(bookList[i].getDescription().c_str());
                response[concatStrInt("course",itemCount).c_str()]        = QString(bookList[i].getCourse().c_str());
                response[concatStrInt("purchasedate",itemCount).c_str()]  = QString(bookList[i].getPurchaseDate().c_str());
                response[concatStrInt("price",itemCount).c_str()]         = QString(bookList[i].getPrice().c_str());
                response[concatStrInt("type",itemCount).c_str()]          = QString(bookList[i].getType().c_str());
                response[concatStrInt("isbn",itemCount).c_str()]          = QString(bookList[i].getISBN().c_str());
                response[concatStrInt("length",itemCount).c_str()]        = QString(bookList[i].getLength().c_str());
                itemCount++;
                qDebug() << bookList[i].getTitle().c_str();
            }

            response["itemCount"] = itemCount;
        } else if (request["request"] == QString("checkout")) {
            QList<Item> checkoutBooks;
            int         itemCount   = request["itemCount"].toDouble();
            std::string user        = request["username"].toString().toStdString();

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
                item.setISBN(response[concatStrInt("isbn",i).c_str()].toString().toStdString());
                item.setLength(response[concatStrInt("length",i).c_str()].toString().toStdString());
                checkoutBooks.push_back(item);
                qDebug() << checkoutBooks.value(i).getTitle().c_str();
            }

            response["status"] = StudentManager().checkout(user, checkoutBooks, myDB);
        } else if (request["request"] == QString("addItem")){

            qDebug() << "mod item request made";
            Item item;
            item.setTitle(request["title"].toString().toStdString());
            item.setAuthor(request["author"].toString().toStdString());
            item.setDescription(request["description"].toString().toStdString());
            item.setCourse(request["course"].toString().toStdString());
            item.setPurchaseDate(request["purchasedate"].toString().toStdString());
            item.setPrice(request["price"].toString().toStdString());
            item.setType(request["type"].toString().toStdString());
            item.setISBN(request["isbn"].toString().toStdString());
            item.setLength(request["length"].toString().toStdString());

            response["status"] = CTMManager().additem(item, myDB);

        } else if (request["request"] == QString("emptyCart")){

            std::string username    = request["username"].toString().toStdString();
            response["status"] = StudentManager().emptyCart(username, myDB);

        }else {
            response["status"] = -403;
            response["message"] = QString("unknown request");
        }

        break;
    }

    rawResponse = QJsonDocument(response);
    socket.write(rawResponse.toJson());
    socket.flush();
    socket.disconnectFromHost();
}
DataBase *Connection::getMyDB() const
{
    return myDB;
}

void Connection::setMyDB(DataBase *value)
{
    myDB = value;
}


std::string Connection::concatStrInt(std::string str, int num){
    std::stringstream test;
    test << str << num;
    return test.str();
}
