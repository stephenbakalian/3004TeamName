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

#include "course.h"
#include "item.h"

class DataBase : public QObject
{
    public:
        DataBase(QObject *parent = 0);
        ~DataBase();

    public:

        //Inserting QStringo DB
        QString createUser(QString, QString, QString, QString);
        int createItem(QString, QString, QString, QString, QString, QString, QString, QString);
        QString createCourse(QString, QString, QString, QString, QString);
        QString createTransaction(QString, QString, QString);
        QString createBilling(QString, QString);
        QString createStudentCourseRelation(QString, QString);
        QString createPurchaseRelation(QString, QString);
        int createCart(QString, QString);


// For these get functions tell me how you want the delimited so you can use them later...
        //Retrieving from DB
        int getUser(QString);
        void getAllUsers();
        QList<Item> getAllItems();
        Item getItem(QString);
        QList<Item> getBook(QString);
        QList<Item> getAllBooks();
        QList<Item> getChapter(QString);
        QList<Item> getAllChapters();
        QList<Item> getSection(QString);
        QList<Item> getAllSections();
        QList<Course> getCourse(QString);
        QList<Course> getAllCourses();
        void getTransaction(QString);
        void getAllTransactions();
        void getBilling(QString);
        QList<Item> getCart(QString);
        QList<Course> getCourseRelation(QString);
        QList<Item> getPurchaseRelation(QString);

        //Updating the DB
        QString updateUser(QString, QString, QString, QString);
        int updateItem(QString, QString, QString, QString, QString, QString, QString, QString);
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
        int deleteCart(QString);

        //Initializatin functions
        bool createTables();
        bool getDBOpen();
        QString getPath();

    private:
        QSqlDatabase mydb;
        QString path;

};

#endif // DATABASE_H
