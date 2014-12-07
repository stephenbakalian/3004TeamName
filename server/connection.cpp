#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>
#include <QList>

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

    QByteArray buffer;
    QJsonDocument rawRequest;
    QJsonObject request;
    QJsonDocument rawResponse;
    QJsonObject response;
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

            qDebug() << "add to cart request made";

            int         itemCount   = request["itemCount"].toDouble();
            std::string user        = request["user"].toString().toStdString();

            std::string itemKey[itemCount];

            for (int i =0; i< itemCount; i++){
                itemKey[i] = request["items"+i].toString().toStdString();
                qDebug() << itemKey[i].c_str();
            }

            response["status"] = StudentManager().addToCart(user, itemKey);

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
                response["title"+itemCount]         = QString(bookList[i].getTitle().c_str());
                response["author"+itemCount]        = QString(bookList[i].getAuthor().c_str());
                response["description"+itemCount]   = QString(bookList[i].getDescription().c_str());
                response["course"+itemCount]        = QString(bookList[i].getCourse().c_str());
                response["purchasedate"+itemCount]  = QString(bookList[i].getPurchaseDate().c_str());
                response["price"+itemCount]         = QString(bookList[i].getPrice().c_str());
                response["type"+itemCount]          = QString(bookList[i].getType().c_str());
                itemCount++;
            //    qDebug() << bookList[i];
            }

            response["itemCount"] = itemCount;

        } else if (request["request"] == QString("viewCart")){

            qDebug() << "view cart request made";
            std::string user        = request["user"].toString().toStdString();
            QList<Item> ownedBooks  = StudentManager().viewCart(user);
            int         itemCount   = 0;


            for (int i =0; i < ownedBooks.size(); i++){

                response["title"+itemCount]         = QString(ownedBooks.value(i).getTitle().c_str());
                response["author"+itemCount]        = QString(ownedBooks.value(i).getAuthor().c_str());
                response["description"+itemCount]   = QString(ownedBooks.value(i).getDescription().c_str());
                response["course"+itemCount]        = QString(ownedBooks.value(i).getCourse().c_str());
                response["purchasedate"+itemCount]  = QString(ownedBooks.value(i).getPurchaseDate().c_str());
                response["price"+itemCount]         = QString(ownedBooks.value(i).getPrice().c_str());
                response["type"+itemCount]          = QString(ownedBooks.value(i).getType().c_str());
                itemCount++;
            }

            response["itemCount"] = ownedBooks.size();


        } else if (request["request"] == QString("checkout")) {
            QList<Item> checkoutBooks;
            int         itemCount   = request["itemCount"].toDouble();
            std::string user        = request["username"].toString().toStdString();

            qDebug() << itemCount;
            for (int i = 0; i < itemCount; i++){
                Item item;
                item.setAuthor(request["author"+i].toString().toStdString());
                item.setCourse(request["course"+i].toString().toStdString());
                item.setDescription(request["description"+i].toString().toStdString());
                item.setPrice(request["price"+i].toString().toStdString());
                item.setPurchaseDate(request["purchasedate"+i].toString().toStdString());
                item.setTitle(request["title"+i].toString().toStdString());
                item.setType(request["type"+itemCount].toString().toStdString());
                checkoutBooks.push_back(item);
                qDebug() << checkoutBooks.value(i).getTitle().c_str();
            }

            response["status"] = StudentManager().checkout(user, checkoutBooks);
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

            response["status"] = CTMManager().additem(item);

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
