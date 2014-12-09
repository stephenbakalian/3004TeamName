#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QDebug>

class DataBase : public QObject
{
    public:
        DataBase(QObject *parent = 0);
        ~DataBase();

    public:

        //Inserting QStringo DB
        QString createUser(QString, QString, QString);
        QString createBook(QString,QString, QString, QString, QString, QString);
        QString createSection(QString, QString, QString, QString, QString, QString);
        QString createChapter(QString, QString, QString, QString, QString, QString);
        QString createCourse(QString, QString, QString, QString, QString, QString);
        QString createTransaction(QString, QString, QString);
        QString createBilling(QString, QString);
        QString createStudentCourseRelation(QString, QString);
        QString createPurchaseRelation(QString, QString);
        QString createCart(QString, QString);


// For these get functions tell me how you want the delimited so you can use them later...
        //Retrieving from DB
        void getUser(QString);
        void getAllUsers();
        void getBook(QString);
        void getAllBooks();
        void getChapter(QString);
        void getAllChapters();
        void getSection(QString);
        void getAllSections();
        void getCourse(QString);
        void getAllCourses();
        void getTransaction(QString);
        void getAllTransactions();
        void getBilling(QString);
        void getCart(QString);

        //Updating the DB
        QString updateUser(QString, QString, QString, QString);
        QString updateBook(QString, QString, QString, QString, QString, QString);
        QString updateSection(QString, QString, QString, QString, QString);
        QString updateChapter(QString, QString, QString, QString, QString, QString);
        QString updateCourse(QString, QString, QString, QString, QString, QString);
        QString updateTransaction(QString, QString, QString, QString);
        QString updateBilling(QString, QString);

        //Deleting from DB
        QString deleteUser(QString);
        QString deleteBook(QString);
        QString deleteSection(QString);
        QString deleteChapter(QString);
        QString deleteCourse(QString);
        QString deleteTransaction(QString);
        QString deleteBilling(QString);
        QString deleteCart(QString);

        //Initializatin functions
        bool createTables();
        bool getDBOpen();
        QString getPath();

    private:
        QSqlDatabase mydb;
        QString path;

};

#endif // DATABASE_H
