#include <QCoreApplication>
#include "database.h"
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DataBase* w = new DataBase();

    /*qDebug() << w->insertItems("Intro to Macro", "Macro", "Textbook",50);
    qDebug() << w->insertItems("Fun", "Fun", "Fun",1000);
    qDebug() << w->insertItems("Boring", "Boring", "Boring",0);
    qDebug() << w->insertItems("Stupid", "Stupid", "Stupid",10);

    w->getItems();
    qDebug() << w->deleteItem(2);
    w->getItems();
    qDebug() << w->insertItems("newFun", "newFun", "newFun",10);
    w->getItems();
    */
    /*qDebug() << w->insertCtm("Lanthier");
    qDebug() << w->insertStudent("Van");

    w->getStudentList();
    w->getCtmList();*/


//   w.getItems();

 //  w.insertStudent("Menan");
 //  w.getStudentList();
//   w.deleteCtm(9);
  //  w.getCtmList();
  // w.updateItems(11,"hello","hello","Textbook",50);
   //TcpServer server;

   return a.exec();

}
