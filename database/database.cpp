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
        /*qry.exec("drop table if exists purchased");
        qry.exec("drop table if exists user");
        qry.exec("drop table if exists course");
        qry.exec("drop table if exists billinginfo");
        qry.exec("drop table if exists book");
        qry.exec("drop table if exists chapter");
        qry.exec("drop table if exists section");*/

        ret = qry.exec("CREATE TABLE purchased "
                       "(purchase_id INTEGER PRIMARY KEY NOT NULL, "
                       "purchase_isbn INTEGER NOT NULL, "
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
                       "FOREIGN_KEY(isbn) REFERENCES book(isbn) ON DELETE CASCADE, "
                       "start_page INTEGER NOT NULL, "
                       "end_page INTEGER NOT NULL, "
                       "price INTEGER, "
                       "title VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE section "
                       "(section_id INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(chapter_id) REFERENCES chapter(chapter_id) ON DELETE CASCADE, "
                       "start_page INTEGER NOT NULL, "
                       "end_page INTEGER NOT NULL, "
                       "price INTEGER) ");

        ret = qry.exec("CREATE TABLE student_course_relation "
                       "(student_number INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(course_code) REFERENCES course(course_code)) ON DELETE CASCADE ");

        ret = qry.exec("CREATE TABLE purchase_relation "
                       "(student_number INTEGER PRIMARY KEY NOT NULL, "
                       "FOREIGN_KEY(purchase_id) REFERENCES purchased(purchase_id)) ON DELETE CASCADE ");


    }
    return ret;
}

bool DataBase::getDBOpen(){

    // Using SQLite DB
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName(getPath());
    return mydb.open();

}

QString DataBase::createTransaction(int purchaseID, int purchaseISBN, int purchasePrice, QString date){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO purchased VALUES(NULL, '%1', '%2', '%3', '%4')")
                       .arg(purchaseID).arg(purchaseISBN).arg(purchasePrice).arg(date));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(purchaseID);
        }

    }
    return newInsert;
}

QString DataBase::createUser(int userID, QString name, QString email, QString role){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO user VALUES(NULL, '%1', '%2', '%3', '%4')")
                       .arg(userID).arg(name).arg(email).arg(role));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(userID);
        }

    }
    return newInsert;
}

QString DataBase::createBook(int ISBN, int price, QString name, QString cover, QString author, int yearPublished){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO book VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(ISBN).arg(price).arg(name).arg(cover).arg(author).arg(yearPublished));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(ISBN);
        }

    }
    return newInsert;
}

QString DataBase::createSection(int sectionID, int chapterID, int startPage, int endPage, int price){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO section VALUES(NULL, '%1', '%2', '%3', '%4', '%5')")
                       .arg(sectionID).arg(chapterID).arg(startPage).arg(endPage).arg(price));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(sectionID);
        }

    }
    return newInsert;
}

QString DataBase::createChapter(int chapterID, int ISBN, int startPage, int endPage, int price, QString title){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO chapter VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(chapterID).arg(ISBN).arg(startPage).arg(endPage).arg(price).arg(title));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(chapterID);
        }

    }
    return newInsert;
}

QString DataBase::createCourse(QString courseCode, QString instructor, QString term, int courseNum, QString building, QString room){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO course VALUES(NULL, '%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(courseCode).arg(instructor).arg(term).arg(courseNum).arg(building).arg(room));

        if (ret){
            newInsert = QString("Inserting %1%2 successful!").arg(courseCode).arg(courseNum);
        }

    }
    return newInsert;
}

QString DataBase::createBilling(int userID, QString address){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO billinginfo VALUES(NULL, '%1', '%2')")
                       .arg(userID).arg(address));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(userID);
        }

    }
    return newInsert;
}

QString DataBase::createStudentCourseRelation(int studentNum, QString courseCode){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO student_course_relation VALUES(NULL, '%1', '%2')")
                       .arg(studentNum).arg(courseCode));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(studentNum);
        }

    }
    return newInsert;
}



QString DataBase::createPurchaseRelation(int studentNum, int purchaseID){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO purchase_relation VALUES(NULL, '%1', '%2')")
                       .arg(studentNum).arg(purchaseID));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(studentNum);
        }

    }
    return newInsert;
}

void DataBase::getUser(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT id,name,email,role FROM user WHERE id = ?");
        qry.addBindValue(search);
        qry.exec();

         while (qry.next()) {

             int userID = qry.value(0).toInt();
             QString name = qry.value(1).toString();
             QString email = qry.value(2).toString();
             QString role = qry.value(3).toString();
             qDebug() << userID << name << email << role;

         }
    }
}

void DataBase::getAllUsers(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT id,name,email,role FROM user");

         while (qry.next()) {

             int userID = qry.value(0).toInt();
             QString name = qry.value(1).toString();
             QString email = qry.value(2).toString();
             QString role = qry.value(3).toString();
             qDebug() << userID << name << email << role;

         }
    }
}
void DataBase:: getBook(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,cover,author,year_published FROM book WHERE isbn = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            int ISBN = qry.value(0).toInt();
            int price = qry.value(1).toInt();
            QString name = qry.value(2).toString();
            QString cover = qry.value(3).toString();
            QString author = qry.value(4).toString();
            int yearPublished = qry.value(5).toInt();

            qDebug() << ISBN << price << name << cover << author << yearPublished;

        }
    }
}

void DataBase:: getAllBooks(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,cover,author,year_published FROM book");

        while (qry.next()) {

            int ISBN = qry.value(0).toInt();
            int price = qry.value(1).toInt();
            QString name = qry.value(2).toString();
            QString cover = qry.value(3).toString();
            QString author = qry.value(4).toString();
            int yearPublished = qry.value(5).toInt();

            qDebug() << ISBN << price << name << cover << author << yearPublished;

        }
    }
}

void DataBase:: getChapter(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT chapter_id,isbn,start_page,end_page,price,title FROM chapter WHERE chapter_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            int chapterID = qry.value(0).toInt();
            int isbn = qry.value(1).toInt();
            int startPage = qry.value(2).toInt();
            int endPage = qry.value(3).toInt();
            int price = qry.value(4).toInt();
            QString title = qry.value(5).toString();

            qDebug() << chapterID << isbn << startPage << endPage << price << title;

        }
    }
}

void DataBase:: getAllChapters(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT chapter_id,isbn,start_page,end_page,price,title FROM chapter");

        while (qry.next()) {

            int chapterID = qry.value(0).toInt();
            int isbn = qry.value(1).toInt();
            int startPage = qry.value(2).toInt();
            int endPage = qry.value(3).toInt();
            int price = qry.value(4).toInt();
            QString title = qry.value(5).toString();

            qDebug() << chapterID << isbn << startPage << endPage << price << title;

        }
    }
}

void DataBase:: getSection(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT section_id,chapter_id,start_page,end_page,price FROM section WHERE section_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            int sectionID = qry.value(0).toInt();
            int chapterID = qry.value(1).toInt();
            int startPage = qry.value(2).toInt();
            int endPage = qry.value(3).toInt();
            int price = qry.value(4).toInt();

            qDebug() << sectionID << chapterID << startPage << endPage << price;

        }
    }
}

void DataBase:: getAllSections(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT section_id,chapter_id,start_page,end_page,price FROM section");

        while (qry.next()) {

            int sectionID = qry.value(0).toInt();
            int chapterID = qry.value(1).toInt();
            int startPage = qry.value(2).toInt();
            int endPage = qry.value(3).toInt();
            int price = qry.value(4).toInt();

            qDebug() << sectionID << chapterID << startPage << endPage << price;

        }
    }
}

void DataBase:: getCourse(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT course_code,instructor,term,course_num,building,room FROM course WHERE course_code = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString courseCode = qry.value(0).toString();
            QString instructor = qry.value(1).toString();
            QString term = qry.value(2).toString();
            int courseNum = qry.value(3).toInt();
            QString building = qry.value(4).toString();
            QString room = qry.value(5).toString();

            qDebug() << courseCode << instructor << term << courseNum << building << room;

        }
    }
}

void DataBase:: getAllCourses(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT course_code,instructor,term,course_num,building,room FROM course");

        while (qry.next()) {

            QString courseCode = qry.value(0).toString();
            QString instructor = qry.value(1).toString();
            QString term = qry.value(2).toString();
            int courseNum = qry.value(3).toInt();
            QString building = qry.value(4).toString();
            QString room = qry.value(5).toString();

            qDebug() << courseCode << instructor << term << courseNum << building << room;

        }
    }
}

void DataBase:: getTransaction(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT purchase_id,purchase_isbn,purchase_price,date FROM purchased WHERE purchase_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            int purchaseID = qry.value(0).toInt();
            int purchaseISBN = qry.value(1).toInt();
            int purchasePrice = qry.value(2).toInt();
            QString date = qry.value(3).toString();

            qDebug() << purchaseID << purchaseISBN << purchasePrice << date;

        }
    }
}

void DataBase:: getAllTransactions(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT purchase_id,purchase_isbn,purchase_price,date FROM purchased");

        while (qry.next()) {

            int purchaseID = qry.value(0).toInt();
            int purchaseISBN = qry.value(1).toInt();
            int purchasePrice = qry.value(2).toInt();
            QString date = qry.value(3).toString();

            qDebug() << purchaseID << purchaseISBN << purchasePrice << date;

        }
    }
}

void DataBase:: getBilling(int search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT user_id,address FROM billinginfo WHERE user_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            int userID = qry.value(0).toInt();
            QString address = qry.value(1).toString();

            qDebug() << userID << address;

        }
    }
}

QString DataBase:: updateUser(int userID, QString name, QString email, QString role){

    QString newUpdate = "Failed to update user table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE user SET name = ?, email = ?, role = ? WHERE userID = ?");
        qry.addBindValue(name);
        qry.addBindValue(email);
        qry.addBindValue(role);
        qry.addBindValue(userID);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(userID);
    }

    return newUpdate;
}

QString DataBase:: updateBook(int ISBN, int price, QString name, QString cover, QString author, int yearPublished){

    QString newUpdate = "Failed to update book table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE book SET price = ?, name = ?, cover = ?, author = ?, year_published = ? WHERE isbn = ?");
        qry.addBindValue(price);
        qry.addBindValue(name);
        qry.addBindValue(cover);
        qry.addBindValue(author);
        qry.addBindValue(yearPublished);
        qry.addBindValue(ISBN);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(ISBN);
    }

    return newUpdate;
}

QString DataBase:: updateSection(int sectionID, int chapterID, int startPage, int endPage, int price){

    QString newUpdate = "Failed to update section table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE section SET chapter_ID = ?, start_page = ?, end_page = ?, price = ?, WHERE section_id = ?");
        qry.addBindValue(chapterID);
        qry.addBindValue(startPage);
        qry.addBindValue(endPage);
        qry.addBindValue(price);
        qry.addBindValue(sectionID);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(sectionID);
    }

    return newUpdate;
}


QString DataBase:: updateChapter(int chapterID, int ISBN, int startPage, int endPage, int price, QString title){

    QString newUpdate = "Failed to update chapter table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE chapter SET isbn = ?, start_page = ?, end_page = ?, price = ?, title = ?, WHERE chapter_id = ?");
        qry.addBindValue(ISBN);
        qry.addBindValue(startPage);
        qry.addBindValue(endPage);
        qry.addBindValue(price);
        qry.addBindValue(title);
        qry.addBindValue(chapterID);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(chapterID);
    }

    return newUpdate;

}


QString DataBase:: updateCourse(QString courseCode, QString instructor, QString term, int courseNum, QString building, QString room){

    QString newUpdate = "Failed to update course table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE course SET instructor = ?, term = ?, course_num = ?, building = ?, room = ?, WHERE course_code = ?");
        qry.addBindValue(instructor);
        qry.addBindValue(term);
        qry.addBindValue(courseNum);
        qry.addBindValue(building);
        qry.addBindValue(room);
        qry.addBindValue(courseCode);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(courseCode);
    }

    return newUpdate;

}

QString DataBase:: updateTransaction(int purchaseID, int purchaseISBN, int purchasePrice, QString date){

    QString newUpdate = "Failed to update transaction table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE purchased SET purchase_isbn = ?, purchase_price = ?, date = ? WHERE purchase_id = ?");
        qry.addBindValue(purchaseISBN);
        qry.addBindValue(purchasePrice);
        qry.addBindValue(date);
        qry.addBindValue(purchaseID);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(purchaseID);
    }

    return newUpdate;

}

QString DataBase:: updateBilling(int userID, QString address){

    QString newUpdate = "Failed to update billinginfo table";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE billinginfo SET address = ? WHERE user_id = ?");
        qry.addBindValue(address);
        qry.addBindValue(userID);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = QString("Updating %1 successful!").arg(userID);
    }

    return newUpdate;

}

QString DataBase:: deleteUser(int search){

    QString newDelete = "Failed to delete user";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM user WHERE id=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;
}
QString DataBase:: deleteBook(int search){

    QString newDelete = "Failed to delete book";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM book WHERE isbn=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}
QString DataBase:: deleteSection(int search){

    QString newDelete = "Failed to delete section";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM section WHERE section_id=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}

QString DataBase:: deleteChapter(int search){

    QString newDelete = "Failed to delete chapter";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM chapter WHERE chapter_id=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}

QString DataBase:: deleteCourse(QString search){

    QString newDelete = "Failed to delete course";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM course WHERE course_code=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}
QString DataBase:: deleteTransaction(int search){

    QString newDelete = "Failed to delete transaction";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM purchased WHERE purchase_id=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}
QString DataBase:: deleteBilling(int search){

    QString newDelete = "Failed to delete billinginfo";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM billinginfo WHERE user_id=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}


QString DataBase::getPath(){return path;}
DataBase::~DataBase(){mydb.close();}
