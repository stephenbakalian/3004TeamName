#include "database.h"


DataBase::DataBase(QObject* parent) : QObject(parent){

    path = QCoreApplication::applicationDirPath()+"/cuTPSDB";
    //qDebug() << path;
    getDBOpen();
    createTables();

}

bool DataBase::createTables(){

    //Create all the tables
    bool ret = false;
    if (mydb.isOpen()){

        QSqlQuery qry;

        //Renews tables each run for testing purposes
        qry.exec("drop table if exists purchased");
        qry.exec("drop table if exists user");
        qry.exec("drop table if exists course");
        qry.exec("drop table if exists billinginfo");
        qry.exec("drop table if exists book");
        qry.exec("drop table if exists chapter");
        qry.exec("drop table if exists section");

        ret = qry.exec("CREATE TABLE purchased "
                       "(purchase_id INTEGER PRIMARY KEY NOT NULL, "
                       "purchase_isbn VARCHAR(255) NOT NULL, "
                       "purchase_price VARCHAR(255) NOT NULL, "
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
                       "course_num VARCHAR(255) NOT NULL, "
                       "building VARCHAR(255), "
                       "room VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE billinginfo "
                       "(user_id INTEGER PRIMARY KEY NOT NULL, "
                       "address TEXT NOT NULL) ");

        ret = qry.exec("CREATE TABLE book "
                       "(isbn VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "price VARCHAR(255) NOT NULL, "
                       "name VARCHAR(255) NOT NULL, "
                       "cover VARCHAR(255), "
                       "author VARCHAR(255) NOT NULL, "
                       "year_published VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE chapter "
                       "(chapter_id VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "isbn VARCHAR(255), "
                       "start_page VARCHAR(255) NOT NULL, "
                       "end_page VARCHAR(255) NOT NULL, "
                       "price VARCHAR(255), "
                       "title VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE section "
                       "(section_id VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "chapter_id VARCHAR(255) NOT NULL, "
                       "start_page VARCHAR(255) NOT NULL, "
                       "end_page VARCHAR(255) NOT NULL, "
                       "price VARCHAR(255), "
                       "title VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE student_course_relation "
                       "(student_number VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "course_code varchar(255) NOT NULL) ");
        //qDebug() << ret;
        ret = qry.exec("CREATE TABLE purchase_relation "
                       "(student_number VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "purchase_id VARCHAR(255) NOT NULL) ");
        //qDebug() << ret;
        ret = qry.exec("CREATE TABLE cart "
                       "(cartID INTEGER PRIMARYflightdb KEY NOT NULL, "
                       "student_number VARCHAR(255) NOT NULL, "
                       "isbn VARCHAR(255) NOT NULL) ");
        //qDebug() << ret;
    }
    return ret;
}

bool DataBase::getDBOpen(){

    // Using SQLite DB
    mydb = QSqlDatabase::addDatabase("QSQLITE");//FILEpath
    mydb.setHostName("cutpsdbthings");
    mydb.setDatabaseName("cuTPSDB");
    return mydb.open();
}

QString DataBase::createTransaction(QString purchaseISBN, QString purchasePrice, QString date){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO purchased VALUES(NULL, '%1', '%2', '%3')")
                       .arg(purchaseISBN).arg(purchasePrice).arg(date));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(purchaseISBN);
        }

    }
    return newInsert;
}

QString DataBase::createUser(QString name, QString email, QString role){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("insert INTO user values(NULL, '%1', '%2', '%3')")
                       .arg(name).arg(email).arg(role));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(name);
        }

    }
    return newInsert;
}

QString DataBase::createBook(QString ISBN, QString price, QString name, QString cover, QString author, QString yearPublished){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO book VALUES('%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(ISBN).arg(price).arg(name).arg(cover).arg(author).arg(yearPublished));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(ISBN);
        }

    }
    return newInsert;
}

QString DataBase::createSection(QString sectionID, QString chapterID, QString startPage, QString endPage, QString price, QString title){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO section VALUES('%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(sectionID).arg(chapterID).arg(startPage).arg(endPage).arg(price).arg(title));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(title);
        }

    }
    return newInsert;
}

QString DataBase::createChapter(QString chapterID, QString ISBN, QString startPage, QString endPage, QString price, QString title){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO chapter VALUES('%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(chapterID).arg(ISBN).arg(startPage).arg(endPage).arg(price).arg(title));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(title);
        }

    }
    return newInsert;
}

QString DataBase::createCourse(QString courseCode, QString instructor, QString term, QString courseNum, QString building, QString room){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO course VALUES('%1', '%2', '%3', '%4', '%5', '%6')")
                       .arg(courseCode).arg(instructor).arg(term).arg(courseNum).arg(building).arg(room));

        if (ret){
            newInsert = QString("Inserting %1%2 successful!").arg(courseCode).arg(courseNum);
        }

    }
    return newInsert;
}

QString DataBase::createBilling(QString userID, QString address){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO billinginfo VALUES('%1', '%2')")
                       .arg(userID).arg(address));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(userID);
        }

    }
    return newInsert;
}

QString DataBase::createStudentCourseRelation(QString studentNum, QString courseCode){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO student_course_relation VALUES('%1', '%2')")
                       .arg(studentNum).arg(courseCode));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(studentNum);
        }

    }
    return newInsert;
}



QString DataBase::createPurchaseRelation(QString studentNum, QString purchaseID){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO purchase_relation VALUES('%1', '%2')")
                       .arg(studentNum).arg(purchaseID));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(studentNum);
        }

    }
    return newInsert;
}

QString DataBase::createCart(QString studentNum, QString ISBN){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO cart VALUES('%1', '%2')")
                       .arg(studentNum).arg(ISBN));

        if (ret){
            newInsert = QString("Inserting to cart %1 successful!").arg(ISBN);
        }

    }
    return newInsert;
}


void DataBase::getUser(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT id,name,email,role FROM user WHERE id = ?");
        qry.addBindValue(search);
        qry.exec();

         while (qry.next()) {

             QString userID = qry.value(0).toString();
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

             QString userID = qry.value(0).toString();
             QString name = qry.value(1).toString();
             QString email = qry.value(2).toString();
             QString role = qry.value(3).toString();
             qDebug() << userID << name << email << role;

         }
    }
}
void DataBase:: getBook(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,cover,author,year_published FROM book WHERE isbn = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString ISBN = qry.value(0).toString();
            QString price = qry.value(1).toString();
            QString name = qry.value(2).toString();
            QString cover = qry.value(3).toString();
            QString author = qry.value(4).toString();
            QString yearPublished = qry.value(5).toString();

            qDebug() << ISBN << price << name << cover << author << yearPublished;

        }
    }
}

void DataBase:: getAllBooks(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,cover,author,year_published FROM book");

        while (qry.next()) {

            QString ISBN = qry.value(0).toString();
            QString price = qry.value(1).toString();
            QString name = qry.value(2).toString();
            QString cover = qry.value(3).toString();
            QString author = qry.value(4).toString();
            QString yearPublished = qry.value(5).toString();

            qDebug() << ISBN << price << name << cover << author << yearPublished;

        }
    }
}

void DataBase:: getChapter(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT chapter_id,isbn,start_page,end_page,price,title FROM chapter WHERE chapter_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString chapterID = qry.value(0).toString();
            QString isbn = qry.value(1).toString();
            QString startPage = qry.value(2).toString();
            QString endPage = qry.value(3).toString();
            QString price = qry.value(4).toString();
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

            QString chapterID = qry.value(0).toString();
            QString isbn = qry.value(1).toString();
            QString startPage = qry.value(2).toString();
            QString endPage = qry.value(3).toString();
            QString price = qry.value(4).toString();
            QString title = qry.value(5).toString();

            qDebug() << chapterID << isbn << startPage << endPage << price << title;

        }
    }
}

void DataBase:: getSection(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT section_id,chapter_id,start_page,end_page,price FROM section WHERE section_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString sectionID = qry.value(0).toString();
            QString chapterID = qry.value(1).toString();
            QString startPage = qry.value(2).toString();
            QString endPage = qry.value(3).toString();
            QString price = qry.value(4).toString();

            qDebug() << sectionID << chapterID << startPage << endPage << price;

        }
    }
}

void DataBase:: getAllSections(){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT section_id,chapter_id,start_page,end_page,price FROM section");

        while (qry.next()) {

            QString sectionID = qry.value(0).toString();
            QString chapterID = qry.value(1).toString();
            QString startPage = qry.value(2).toString();
            QString endPage = qry.value(3).toString();
            QString price = qry.value(4).toString();

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
            QString courseNum = qry.value(3).toString();
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
            QString courseNum = qry.value(3).toString();
            QString building = qry.value(4).toString();
            QString room = qry.value(5).toString();

            qDebug() << courseCode << instructor << term << courseNum << building << room;

        }
    }
}

void DataBase:: getTransaction(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT purchase_id,purchase_isbn,purchase_price,date FROM purchased WHERE purchase_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString purchaseID = qry.value(0).toString();
            QString purchaseISBN = qry.value(1).toString();
            QString purchasePrice = qry.value(2).toString();
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

            QString purchaseID = qry.value(0).toString();
            QString purchaseISBN = qry.value(1).toString();
            QString purchasePrice = qry.value(2).toString();
            QString date = qry.value(3).toString();

            qDebug() << purchaseID << purchaseISBN << purchasePrice << date;

        }
    }
}

void DataBase:: getBilling(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT user_id,address FROM billinginfo WHERE user_id = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            QString userID = qry.value(0).toString();
            QString address = qry.value(1).toString();

            qDebug() << userID << address;

        }
    }
}

void DataBase::getCart(QString search){

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn FROM cart WHERE student_number = ?");
        qry.addBindValue(search);
        qry.exec();

         while (qry.next()) {

             QString ISBN = qry.value(0).toString();
             qDebug() << ISBN;

         }
    }
}

QString DataBase:: updateUser(QString userID, QString name, QString email, QString role){

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

QString DataBase:: updateBook(QString ISBN, QString price, QString name, QString cover, QString author, QString yearPublished){

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

QString DataBase:: updateSection(QString sectionID, QString chapterID, QString startPage, QString endPage, QString price){

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


QString DataBase:: updateChapter(QString chapterID, QString ISBN, QString startPage, QString endPage, QString price, QString title){

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


QString DataBase:: updateCourse(QString courseCode, QString instructor, QString term, QString courseNum, QString building, QString room){

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

QString DataBase:: updateTransaction(QString purchaseID, QString purchaseISBN, QString purchasePrice, QString date){

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

QString DataBase:: updateBilling(QString userID, QString address){

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

QString DataBase:: deleteUser(QString search){

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
QString DataBase:: deleteBook(QString search){

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
QString DataBase:: deleteSection(QString search){

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

QString DataBase:: deleteChapter(QString search){

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
QString DataBase:: deleteTransaction(QString search){

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

QString DataBase:: deleteBilling(QString search){

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

QString DataBase:: deleteCart(QString search){

    QString newDelete = "Failed to delete cart";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM cart WHERE student_number=%1")
                       .arg(search));

        if (ret){
            newDelete = QString("Deleting %1 successful!").arg(search);
        }
    }

    return newDelete;

}

QString DataBase::getPath(){return path;}
DataBase::~DataBase(){mydb.close();}
