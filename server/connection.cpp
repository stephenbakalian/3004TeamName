#include <QDebug>
#include <QtNetwork>
#include <QJsonDocument>

#include "connection.h"

Connection::Connection(QObject *parent, int socketDesc) :
QThread(parent), socketDesc(socketDesc) {
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

            qDebug() << "Login request made";

//TODO this is a place holder
            if (request["username"] == QString("student")) {
                qDebug() << "student";
                response["status"] = 2;
            } else if (request["username"] == QString("contentmanager")) {
                qDebug() << "CTM";
                response["status"] = 3;
            } else if (request["username"] == QString("admin")) {
                qDebug() << "admin";
                response["status"] = 4;
            } else {
                qDebug() << "failed";
                response["status"] = -1;
            }

        } else if (request["request"] == QString("addbook")) {
            std::string bookName    = request["bookName"].toString().toStdString();
            int         bookEdition = request["bookEdition"].toDouble();
            std::string authorName  = request["authorName"].toString().toStdString();
            int         yearPublished   = request["yearPublished"].toDouble();
            double      bookPrice   = request["bookPrice"].toDouble();
            std::string bookISBN    = request["bookISBN"].toString().toStdString();

        } else if (request["request"] == QString("addcourse")) {
            std::string courseCode  = request["courseCode"].toString().toStdString();
            std::string courseInstructor  = request["courseInstructor"].toString().toStdString();
            std::string courseTerm  = request["courseTerm"].toString().toStdString();
            int         courseNum   = request["courseNum"].toDouble();
            std::string courseLocation    = request["courseLocation"].toString().toStdString();

        } else if (request["request"] == QString("buybook")) {
            std::string studentName = request["studentName"].toString().toStdString();
            std::string bookISBN = request["bookISBN"].toString().toStdString();

        } else {
            response["status"] = -2;
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

bool addToPreviouslyPurchasedBooks(std::string studentName, std::string ISBN) {
    //TODO
    return false;
}

bool addChapter(int startPage, int endPage, double price, std::string title, std::string bookISBN){
//TODO
    return false;
}


bool addSection(int startPage, int endPage, double price, std::string ISBN, std::string chpTitle){
//TODO
    return false;
}
/*
int sectionID;
int sectionStrPg;
int sectionsEndPg;
double price;*/

