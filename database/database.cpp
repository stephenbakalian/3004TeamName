#include "database.h"


DataBase::DataBase(QObject* parent) : QObject(parent){

    path = QCoreApplication::applicationFilePath()+"/cuTPSDB";
    getDBOpen();
    createTables();

}

bool DataBase::createTables(){

    //Create all the tables
    bool ret = false;
    if (mydb.isOpen()){

        QSqlQuery qry;

        //Renews tables each run for testing purposes
        //qry.exec("drop table if exists items");
        //qry.exec("drop table if exists students");
        //qry.exec("drop table if exists ctm");

        ret = qry.exec("CREATE TABLE purchased "
                       "(purchase_id INTEGER PRIMARY KEY NOT NULL, "
                       "purchased_isbn INTEGER NOT NULL, "
                       "purchase_price INTEGER NOT NULL, "
                       "date TEXT NOT NULL) ");

        ret = qry.exec("CREATE TABLE user "
                        "(id INTEGER PRIMARY KEY NOT NULL, "
                        "name VARCHAR(255) NOT NULL, "
                        "email VARCHAR(255) NOT NULL, "
                        "role VARCHAR(20) NOT NULL) ");

        ret = qry.exec("CREATE TABLE course "
                       "(course_code VARCHAR(10) PRIMARY KEY NOT NULL, "
                       "instructor VARCHAR(255) NOT NULL, "
                       "term VARCHAR(6) NOT NULL, "
                       "course_num INTEGER NOT NULL, "
                       "building VARCHAR(255), "
                       "room VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE billinginfo "
                       "(user_id INTEGER PRIMARY KEY NOT NULL, "
                       "address TEXT NOT NULL) ");

        ret = qry.exec("CREATE TABLE book "
                       "(isbn INTEGER PRIMARY KEY NOT NULL, "
                       "price INTEGER NOT NULL, "
                       "name VARCHAR(255) NOT NULL, "
                       "cover VARCHAR(255), "
                       "author VARCHAR(255) NOT NULL, "
                       "year_published INTEGER) ");

        ret = qry.exec("CREATE TABLE chapter "
                       "(chapter_id INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(isbn) REFERENCES book(isbn), "
                       "start_page INTEGER NOT NULL, "
                       "end_page INTEGER NOT NULL, "
                       "price INTEGER, "
                       "title VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE section "
                       "(section_id INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(chapter_id) REFERENCES chapter(chapter_id), "
                       "start_page INTEGER NOT NULL, "
                       "end_page INTEGER NOT NULL, "
                       "price INTEGER) ");

        ret = qry.exec("CREATE TABLE student_course_relation "
                       "(student_number INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(course_code) REFERENCES course(course_code)) ");

        ret = qry.exec("CREATE TABLE purchase_relation "
                       "(student_number INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(purchase_id) REFERENCES purchased(purchase_id)) ");


    }
    return ret;
}

bool DataBase::getDBOpen(){

    // Using SQLite DB
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(getPath());
    return mydb.open();

}

QString DataBase::insertItems(QString title, QString description, QString type, int cost){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("insert into items values(NULL, '%1', '%2', '%3', '%4')")
                       .arg(title).arg(description).arg(type).arg(cost));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(title);
        }

    }
    return newInsert;
}

void DataBase:: getItems(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT id,title,description,type,cost FROM items");

        while (qry.next()) {

            int id = qry.value(0).toInt();
            QString title = qry.value(1).toString();
            QString description = qry.value(2).toString();
            QString type = qry.value(3).toString();
            int cost = qry.value(4).toInt();
            qDebug() << id << title << description << type << cost;

        }
    }
}

void DataBase::getStudentList(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT username FROM students");

         while (qry.next()) {

                QString username = qry.value(0).toString();
                qDebug() << username;

         }
    }
}

void DataBase::getCtmList(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT username FROM ctm");

        while (qry.next()) {

            QString username = qry.value(0).toString();
            qDebug() << username;

        }
    }
}

QString DataBase::insertStudent (QString username){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("insert into students values('%1')")
                       .arg(username));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(username);
        }

    }
    return newInsert;
}


QString DataBase::insertCtm(QString username){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("insert into ctm values('%1')")
                       .arg(username));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(username);
        }

    }
    return newInsert;
}

QString DataBase::deleteItem(int id){

    QString newDelete = "Failed to delete item";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("delete from items where id=%1")
                       .arg(id));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(id);
        }
    }
    return newDelete;
}


QString DataBase::deleteStudent(int id){

    QString newDelete = "Failed to delete student";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery query;

        ret = query.exec(QString("delete from students where id=%1")
                         .arg(id));

        if(ret){
            newDelete = QString("Deleting %1 successful!").arg(id);
        }
    }
    return newDelete;
}

QString DataBase::deleteCtm(int id){

    QString newDelete = "Failed to delete CTM";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery query;

        ret = query.exec(QString("delete from ctm where id=%1")
                         .arg(id));

        if(ret){
            newDelete = QString("Deleting %1 successful!").arg(id);
        }
    }
    return newDelete;

}

/*void DataBase::updateItems(int id, QString title, QString description, QString type, int cost){

    QString newUpdate = "";
    bool ret = false;

    if (mydb.isOpen()){
        QSqlQuery qry;

        query.prepare("update items set title='"+title+"',description='"+description+"',type='"+type+"',cost= :cost where id= :id");
        query.bindValue(":id",id);
        query.bindValue(":cost",cost);
        query.exec();

}*/

QString DataBase::getPath(){return path;}
DataBase::~DataBase(){mydb.close();}
