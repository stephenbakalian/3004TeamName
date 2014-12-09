#include "ownedbooks.h"
#include "ui_ownedbooks.h"
#include "mainwindow.h"

/**
 * Page used to display books already owned by the user
 * @brief OwnedBooks::OwnedBooks
 * @param parent
 */
OwnedBooks::OwnedBooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OwnedBooks)
{
    ui->setupUi(this);

}


OwnedBooks::~OwnedBooks()
{
    delete ui;
}

//view student items was slected>send to view items page
void OwnedBooks::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems(username);
}
//logout pressed send to login
void OwnedBooks::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}
//show items that the user had in their cart
void OwnedBooks::showItems(QList<Item> list){
   int x;
   QLabel *titles[list.size()];
   QLabel *type[list.size()];
   QLabel *price[list.size()];
   QLabel *description[list.size()];


   for(x=0;x < list.size(); x++){
         titles[x] = new QLabel(QString::fromUtf8(list.value(x).getTitle().c_str()));
         ui->gridLayout->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list.value(x).getType().c_str()));
         ui->gridLayout->addWidget(type[x],x+1,1,1,1);

         price[x] = new QLabel(QString::fromUtf8(list.value(x).getPrice().c_str()));
         ui->gridLayout->addWidget(price[x],x+1,2,1,1);

         description[x] = new QLabel(QString::fromUtf8(list.value(x).getDescription().c_str()));
         ui->gridLayout->addWidget(description[x],x+1,3,1,1);
   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->gridLayout->addItem(spacer,list.size(),5,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->gridLayout->addItem(vert,list.size()+1,0,1,0);
   ui->scrollArea->setStyleSheet("background-color:transparent;");

   ui->scrollAreaWidgetContents->setMinimumHeight(28*sizeof(list)+1);
}
//sets the username
void OwnedBooks::setUsername(std::string newUsername){
    username=newUsername;
    updateUI();
}


void OwnedBooks::updateUI(){

    reqHandler = new RequestHandler(this);
    QList<Item> items;

    items = reqHandler->booksOwned(username);


    showItems(items);

}
