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

        //Retrieving from DB
        void getUser();
        void getAllUsers();
        void getBook();
        void getAllBooks();
        void getChapter();
        void getAllChapters();
        void getSection();
        void getAllSections();
        void getCourse();
        void getAllCourses();
        void getTransaction();
        void getAllTransactions();
        void getBilling();

        //Updating the DB
        QString updateUser();
        QString updateBook();
        QString updateSection();
        QString updateChapter();
        QString updateCourse();
        QString updateTransaction();
        QString updateBilling();

        //Deleting from DB
        QString deleteUser();
        QString deleteBook();
        QString deleteSection();
        QString deleteChapter();
        QString deleteCourse();
        QString deleteTransaction();
        QString deleteBilling();

        //Initializatin functions
        bool createTables();
        bool getDBOpen();
        QString getPath();

    private:
        QSqlDatabase mydb;
        QString path;

};

#endif // DATABASE_H
