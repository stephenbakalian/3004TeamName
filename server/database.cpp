#include "database.h"
#include "course.h"
#include "item.h"

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
        qry.exec("drop table if exists cart");
        qry.exec("drop table if exists student_course_relation");
        qry.exec("drop table if exists purchase_relation");

        ret = qry.exec("CREATE TABLE purchased "
                       "(purchase_id INTEGER PRIMARY KEY NOT NULL, "
                       "purchase_isbn VARCHAR(255) NOT NULL, "
                       "purchase_price VARCHAR(255) NOT NULL, "
                       "date TEXT NOT NULL) ");

        ret = qry.exec("CREATE TABLE user "
                       "(id VARCHAR(255) PRIMARY KEY NOT NULL, "
                        "name VARCHAR(255) NOT NULL, "
                        "email VARCHAR(255) NOT NULL, "
                        "role VARCHAR(20) NOT NULL) ");

        ret = qry.exec("CREATE TABLE course "
                       "(course_code VARCHAR(10) PRIMARY KEY NOT NULL, "
                       "instructor VARCHAR(255) NOT NULL, "
                       "term VARCHAR(6) NOT NULL, "
                       "building VARCHAR(255), "
                       "room VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE billinginfo "
                       "(user_id VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "address TEXT NOT NULL) ");

        ret = qry.exec("CREATE TABLE item "
                       "(isbn VARCHAR(255) PRIMARY KEY NOT NULL, "
                       "price VARCHAR(255) NOT NULL, "
                       "name VARCHAR(255) NOT NULL, "
                       "author VARCHAR(255), "
                       "description VARCHAR(255), "
                       "length VARCHAR(255), "
                       "type VARCHAR(255) NOT NULL, "
                       "course VARCHAR(255)) ");

        ret = qry.exec("CREATE TABLE student_course_relation "
                       "(student_number VARCHAR(255) NOT NULL, "
                       "course_code varchar(255) NOT NULL) ");
        //qDebug() << ret;
        ret = qry.exec("CREATE TABLE purchase_relation "
                       "(student_number VARCHAR(255) NOT NULL, "
                       "purchase_id VARCHAR(255) NOT NULL) ");
        //qDebug() << ret;
        ret = qry.exec("CREATE TABLE cart "
                       "(student_number VARCHAR(255) NOT NULL, "
                       "isbn VARCHAR(255) NOT NULL) ");
        //qDebug() << ret;

        createItem("1000", "100", "Software Engineering", "Christine", "A Book about Software Engineering", "500", "Textbook", "Comp 3005");
        createItem("1001", "50", "Intro to Database", "Christine", "A Book about Database", "550", "Textbook", "Comp 3004");
        createItem("1002", "1000", "Intro to Networking", "Christine", "A Book about Networking", "600", "Textbook", "Comp 3007");

        createItem("100", "25", "Chapter 1: Software Engineering", "Christine", "A chapter about Software Engineering", "30", "chapter", "Comp 3005");
        createItem("101", "30", "Chapter 2: Database", "Christine", "A chapter about Database", "24", "chapter", "Comp 3004");
        createItem("102", "20", "Chapter 3: Networking", "Christine", "A chapter about Networking", "25", "chapter", "Comp 3007");

        createItem("10", "5", "Section 2.1 Software Engineering", "Christine", "A Section about Software Engineering", "1", "section", "Comp 3005");
        createItem("11", "4", "Section 1,2 Database", "Christine", "A Section about Database", "2", "section", "Comp 3004");
        createItem("12", "3", "Section 3.3 Networking", "Christine", "A Section about Networking", "1", "section", "Comp 3007");

        createCourse("COMP 3005", "Christine", "Fall 2014", "Tory Building", "TB230");
        createCourse("COMP 3004", "Christine", "Fall 2015", "Tory Building", "TB231");
        createCourse("COMP 3007", "Christine", "Winter 2014", "Tory Building", "TB232");

        createUser("100770196", "Jason", "Jason@hotmail.com", "2");
        createUser("100884228", "Jon", "Jon@hotmail.com", "3");

        createUser("student", "Jason", "Jason@hotmail.com", "2");
        createUser("ctm", "Jon", "Jon@hotmail.com", "3");
        createUser("admin", "Jon", "Jon@hotmail.com", "4");

        createStudentCourseRelation("100770196", "COMP 3004");
        createStudentCourseRelation("100770196", "COMP 3005");
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

QString DataBase::createUser(QString id, QString name, QString email, QString role){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("insert INTO user values('%1', '%2', '%3','%4')")
                       .arg(id).arg(name).arg(email).arg(role));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(id);
        }

    }
    return newInsert;
}

int DataBase::createItem(QString ISBN, QString price, QString name, QString author, QString description, QString length, QString type, QString course){

    int newInsert = -1;
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO item VALUES('%1', '%2', '%3', '%4', '%5','%6','%7','%8')")
                       .arg(ISBN).arg(price).arg(name).arg(author).arg(description).arg(length).arg(type).arg(course));

        if (ret){
            newInsert = 1;
        }

    }
    return newInsert;
}

QString DataBase::createCourse(QString courseCode, QString instructor, QString term, QString building, QString room){

    QString newInsert = "Failed to insert new query";
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO course VALUES('%1', '%2', '%3', '%4', '%5')")
                       .arg(courseCode).arg(instructor).arg(term).arg(building).arg(room));

        if (ret){
            newInsert = QString("Inserting %1 successful!").arg(courseCode);
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

int DataBase::createCart(QString studentNum, QString ISBN){

    int newInsert = -1;
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;

        ret = qry.exec(QString("INSERT INTO cart VALUES('%1', '%2')")
                       .arg(studentNum).arg(ISBN));

        if (ret){
            newInsert = 1;
        }

    }
    return newInsert;
}


int DataBase::getUser(QString search){

    int userType = -1;

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
             //qDebug() << userID << name << email << role;
             if (role == "2"){
                 userType = 2;
             }
             if (role == "3"){
                 userType = 3;
             }
             if (role == "4"){
                 userType = 4;
             }
         }
    }
    return userType;
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
QString DataBase:: getItem(QString search){

    Item item;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,author,description,length,type,course FROM item WHERE isbn = ?");
        qry.addBindValue(search);
        qry.exec();


        item.setISBN(qry.value(0).toString().toStdString());
        item.setPrice(qry.value(1).toString().toStdString());
        item.setTitle(qry.value(2).toString().toStdString());
        item.setAuthor(qry.value(3).toString().toStdString());
        item.setDescription(qry.value(4).toString().toStdString());
        item.setLength(qry.value(5).toString().toStdString());
        item.setType(qry.value(6).toString().toStdString());
        item.setCourse(qry.value(7).toString().toStdString());

    }
    return QString::fromStdString(item.getISBN());
}


QList<Item> DataBase:: getAllItems(){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,author,description,length,type,course FROM item");

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << ISBN << price << name << author << yearPublished;
        itemList.push_back(item);
        }
    }
    return itemList;
}


QList<Item> DataBase:: getBook(QString search){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,author,description,length,type,course FROM item WHERE isbn = ? and type = 'Textbook'");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << ISBN << price << name << author << yearPublished;
        itemList.push_back(item);
        }
    }
    return itemList;
}

QList<Item> DataBase:: getAllBooks(){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,author,description,length,type,course FROM item where type = 'Textbook'");

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << ISBN << price << name << author << yearPublished;
        itemList.push_back(item);
        }
    }
    return itemList;
}

QList<Item> DataBase:: getChapter(QString search){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,author,description,length,type,course FROM item WHERE isbn = ? and type = 'chapter'");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << chapterID << isbn << startPage << endPage << price << title;

         itemList.push_back(item);
        }
    }
    return itemList;
}

QList<Item> DataBase:: getAllChapters(){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,author,description,length,type,course FROM item WHERE type = 'chapter'");

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << chapterID << isbn << startPage << endPage << price << title;

         itemList.push_back(item);

        }
    }
    return itemList;
}

QList<Item> DataBase:: getSection(QString search){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn,price,name,author,description,length,type,course FROM item WHERE isbn = ? and type = 'section'");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << chapterID << isbn << startPage << endPage << price << title;        QString createSection(QString, QString, QString, QString, QString, QString, QString, QString);
            QString createChapter(QString, QString, QString, QString, QString, QString, QString, QString);

         itemList.push_back(item);
        }
   }
   return itemList;
}

QList<Item> DataBase:: getAllSections(){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT isbn,price,name,author,description,length,type,course FROM section where type = 'section'");

        while (qry.next()) {

            Item item;

            item.setISBN(qry.value(0).toString().toStdString());
            item.setPrice(qry.value(1).toString().toStdString());
            item.setTitle(qry.value(2).toString().toStdString());
            item.setAuthor(qry.value(3).toString().toStdString());
            item.setDescription(qry.value(4).toString().toStdString());
            item.setLength(qry.value(5).toString().toStdString());
            item.setType(qry.value(6).toString().toStdString());
            item.setCourse(qry.value(7).toString().toStdString());

            //qDebug() << chapterID << isbn << startPage << endPage << price << title;

         itemList.push_back(item);
        }
   }
   return itemList;
}

QList<Course> DataBase:: getCourse(QString search){

    QList<Course> courseList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT course_code,instructor,term,building,room FROM course WHERE course_code = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            Course course;

            course.setCourseCode(qry.value(0).toString().toStdString());
            course.setInstructor(qry.value(1).toString().toStdString());
            course.setTerm(qry.value(2).toString().toStdString());
            course.setBuilding(qry.value(3).toString().toStdString());
            course.setRoom(qry.value(4).toString().toStdString());

            //qDebug() << courseCode << instructor << term << courseNum << building << room;

            courseList.push_back(course);
        }
    }
    return courseList;
}

QList<Course> DataBase:: getAllCourses(){

    QList<Course> courseList;
    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.exec("SELECT course_code,instructor,term,building,room FROM course");

        while (qry.next()) {

        Course course;

        course.setCourseCode(qry.value(0).toString().toStdString());
        course.setInstructor(qry.value(1).toString().toStdString());
        course.setTerm(qry.value(2).toString().toStdString());
        course.setBuilding(qry.value(3).toString().toStdString());
        course.setRoom(qry.value(4).toString().toStdString());

        //qDebug() << courseCode << instructor << term << courseNum << building << room;

        courseList.push_back(course);
        }
    }
    return courseList;
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

QList<Course> DataBase:: getCourseRelation(QString search){

    QList<Course> courseList;

    if (mydb.isOpen()){

        QSqlQuery qry;

        qry.prepare("SELECT course_code FROM student_course_relation WHERE student_number = ?");
        qry.addBindValue(search);
        qry.exec();

        while (qry.next()) {

            Course course;
            course.setCourseCode(qry.value(0).toString().toStdString());
            courseList.push_back(course);
        }
    }
    return courseList;
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

QList<Item> DataBase::getCart(QString search){

    QList<Item> itemList;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("SELECT isbn FROM cart WHERE student_number = ?");
        qry.addBindValue(search);
        qry.exec();

         while (qry.next()) {

             Item item;
             item.setISBN(qry.value(0).toString().toStdString());
             itemList.push_back(item);
         }
    }
    return itemList;
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

int DataBase:: updateItem(QString ISBN, QString price, QString name, QString author, QString description, QString length, QString type, QString course){

    int newUpdate = -1;
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        qry.prepare("UPDATE chapter SET isbn = ?, price = ?, name = ?, author = ?, description = ?, length = ?, type = ?, course = ? WHERE isbn = ?");
        qry.addBindValue(ISBN);
        qry.addBindValue(price);
        qry.addBindValue(name);
        qry.addBindValue(author);
        qry.addBindValue(description);
        qry.addBindValue(length);
        qry.addBindValue(type);
        qry.addBindValue(course);
        qry.addBindValue(ISBN);
        ret = qry.exec();
    }

    if (ret){
        newUpdate = 1;
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

int DataBase:: deleteCart(QString search){

    int newDelete = -1;
    bool ret = false;

    if (mydb.isOpen()){

        QSqlQuery qry;
        ret = qry.exec(QString("DELETE FROM cart WHERE student_number=%1")
                       .arg(search));

        if (ret){
            newDelete = 1;
        }
    }

    return newDelete;

}

QString DataBase::getPath(){return path;}
DataBase::~DataBase(){mydb.close();}
