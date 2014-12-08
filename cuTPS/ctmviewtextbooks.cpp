#include "ctmviewtextbooks.h"
#include "ui_ctmviewtextbooks.h"
#include "mainwindow.h"
CTMViewTextbooks::CTMViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTMViewTextbooks)
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

CTMViewTextbooks::~CTMViewTextbooks()
{
    delete ui;
}

void CTMViewTextbooks::setUsername(std::string user){
    username=user;
}

void CTMViewTextbooks::on_pushButton_16_clicked() //edit button had been pressed
{
    QString temp[]= {"1","THIS IS A PLACEHOLDER"};
    ((MainWindow*)parentWidget())->setViewModItems(temp, username);
}

void CTMViewTextbooks::on_pushButton_3_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();
}

void CTMViewTextbooks::on_pushButton_clicked()//new Button has been pressed
{
    ((MainWindow*)parentWidget())->setViewModItems(username);

}
void CTMViewTextbooks::showItems(Item list[]){
   //ui->gridLayout
   int x;
   QLabel *titles[sizeof(list)];
   QLabel *type[sizeof(list)];
   QLabel *price[sizeof(list)];
   QLabel *description[sizeof(list)];
   QPushButton *details[sizeof(list)];

   for(x=0;x < sizeof(list); x++){
         titles[x] = new QLabel(QString::fromUtf8(list[x].getTitle().c_str()));
         ui->itemGrid->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list[x].getType().c_str()));
         ui->itemGrid->addWidget(type[x],x+1,1,1,1);


         price[x] = new QLabel(QString::fromUtf8(list[x].getPrice().c_str()));
         ui->itemGrid->addWidget(price[x],x+1,2,1,1);


         description[x] = new QLabel(QString::fromUtf8(list[x].getDescription().c_str()));
         ui->itemGrid->addWidget(description[x],x+1,3,1,1);

         details[x] = new QPushButton("Details");
         ui->itemGrid->addWidget(details[x],x+1,4,1,1);

   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->itemGrid->addItem(spacer,sizeof(list),4,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->itemGrid->addItem(vert,sizeof(list)+1,0,1,0);
}
void CTMViewTextbooks::showDetails(Item showItem){
    //Title,length,price,author,ISBN,course, description,type
     //OPtional->chapter->textbook
    ui->SelectedTitle->setText (QString::fromUtf8(showItem.getTitle().c_str()));
    ui->SelectedAuthor->setText(QString::fromUtf8(showItem.getAuthor().c_str()));
    ui->SelectedCourse->setText(QString::fromUtf8(showItem.getCourse().c_str()));
    ui->SelectedType->setText  (QString::fromUtf8(showItem.getType().c_str()));
    ui->SelectedISBN->setText  (QString::fromUtf8(showItem.getISBN().c_str()));
    ui->SelectedLength->setText(QString::fromUtf8(showItem.getLength().c_str()));
    ui->SelectedPrice->setText (QString::fromUtf8(showItem.getPrice().c_str()));
    if(showItem.getType()=="asdf"){
        ui->SelectedTexbook->setText (QString::fromUtf8(showItem.getPrice().c_str()));
    }
    if(showItem.getType()=="asdf"){
        ui->SelectedTexbook->setText (QString::fromUtf8(showItem.getPrice().c_str()));
        ui->SelectedChapter->setText(QString::fromUtf8(showItem.getPrice().c_str()));
    }
}
