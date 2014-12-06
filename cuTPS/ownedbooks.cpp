#include "ownedbooks.h"
#include "ui_ownedbooks.h"
#include "mainwindow.h"
OwnedBooks::OwnedBooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnedBooks)
{
    ui->setupUi(this);


    Item *temp1 = new Item();
    Item *temp2 = new Item();
    Item *temp3 = new Item();
    Item *temp4 = new Item();

    temp1->setTitle("HOW TO WIN at chess");
    temp2->setTitle("Batman beyond");
    temp3->setTitle("duck you");
    temp4->setTitle("Hai");

    Item literature[]={*temp1,*temp2,*temp3,*temp4};
    /**
      HERE ITEMS SHOULD BE GRABBED FROM SERVER
     **/
    showItems(literature);
}

OwnedBooks::~OwnedBooks()
{
    delete ui;
}

void OwnedBooks::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems();
}

void OwnedBooks::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}
void OwnedBooks::showItems(Item list[]){
   //ui->gridLayout
   int x;
   QLabel *titles[sizeof(list)];
   QLabel *type[sizeof(list)];
   QLabel *price[sizeof(list)];
   QLabel *purchaseDate[sizeof(list)];
   QLabel *description[sizeof(list)];


   for(x=0;x < sizeof(list); x++){
         titles[x] = new QLabel(QString::fromUtf8(list[x].getTitle().c_str()));
         ui->gridLayout->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list[x].getType().c_str()));
         ui->gridLayout->addWidget(type[x],1,x);

         price[x] = new QLabel(QString::fromUtf8(list[x].getPrice().c_str()));
         ui->gridLayout->addWidget(price[x],2,x);

         purchaseDate[x] = new QLabel(QString::fromUtf8(list[x].getPurchaseDate().c_str()));
         ui->gridLayout->addWidget(purchaseDate[x],3,x);

         description[x] = new QLabel(QString::fromUtf8(list[x].getDescription().c_str()));
         ui->gridLayout->addWidget(description[x],4,x);
   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->gridLayout->addItem(spacer,sizeof(list),5,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->gridLayout->addItem(vert,sizeof(list)+1,0,1,0);
}

