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

        //Inserting into DB
        QString createUser(int, QString, QString, QString);
        QString createBook(int, int, QString, QString, QString, int);
        QString createSection(int, int, int, int, int);
        QString createChapter(int, int, int, int, int, QString);
        QString createCourse(QString, QString, QString, int, QString, QString); 
        QString createTransaction(int, int, int, QString);
        QString createBilling(int, QString);
        QString createStudentCourseRelation(int, QString);
        QString DataBase::createPurchaseRelation(int, int);


// For these get functions tell me how you want the delimited so you can use them later...
        //Retrieving from DB
        void getUser(int);
        void getAllUsers();
        void getBook(int);
        void getAllBooks();
        void getChapter(int);
        void getAllChapters();
        void getSection(int);
        void getAllSections();
        void getCourse(QString);
        void getAllCourses();
        void getTransaction(int);
        void getAllTransactions();
        void getBilling(int);

        //Updating the DB
        QString updateUser(int, QString, QString, QString);
        QString updateBook(int, int, QString, QString, QString, int);
        QString updateSection(int, int, int, int, int);
        QString updateChapter(int, int, int, int, int, QString);
        QString updateCourse(QString, QString, QString, int, QString, QString);
        QString updateTransaction(int, int, int, QString);
        QString updateBilling(int, QString);

        //Deleting from DB
        QString deleteUser(int);
        QString deleteBook(int);
        QString deleteSection(int);
        QString deleteChapter(int);
        QString deleteCourse(QString);
        QString deleteTransaction(int);
        QString deleteBilling(int);

        //Initializatin functions
        bool createTables();
        bool getDBOpen();
        QString getPath();

    private:
        QSqlDatabase mydb;
        QString path;

};

#endif // DATABASE_H
