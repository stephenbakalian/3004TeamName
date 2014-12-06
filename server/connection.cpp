#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>

#include "connection.h"
#include "sharedmanager.h"
#include "studentmanager.h"

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

        } else if (request["request"] == QString("addbook")) {

        } else if (request["request"] == QString("addcourse")) {

        } else if (request["request"] == QString("buybook")) {


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


//================================================================
//          Methods to enter data into the database
//================================================================

// add a book to the database, but if it already exists then update the entry
bool addBook(std::string textbookName, int edition, std::string author, int yearPusblihed, double price, std::string ISBN) {
//TODO
    return false;
}

bool addCourse(std::string courseCode, std::string instructor, std::string term, int courseNum, std::string location){
//TODO
    return false;
}

void selectCourses(){
//TODO
}

void selectBooks(){
//TODO
}

bool addChapter(int startPage, int endPage, double price, std::string title, std::string bookISBN){
//TODO
    return false;
}

bool addSection(int startPage, int endPage, double price, std::string ISBN, std::string chpTitle){
//TODO
    return false;
}

