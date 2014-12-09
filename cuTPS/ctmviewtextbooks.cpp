#include "ctmviewtextbooks.h"
#include "ui_ctmviewtextbooks.h"
#include "mainwindow.h"
#include "requesthandler.h"

CTMViewTextbooks::CTMViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTMViewTextbooks)
{
    ui->setupUi(this);
}

CTMViewTextbooks::~CTMViewTextbooks()
{
    delete ui;
}

void CTMViewTextbooks::setUsername(std::string user){
    username=user;
    updateUI();
}

void CTMViewTextbooks::updateUI(){
    reqHandler = new RequestHandler(this);
    items = reqHandler->getAllItems();
    showItems(items);
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
void CTMViewTextbooks::showItems(QList<Item> list){
   //ui->gridLayout
   int x;
   QLabel *titles[list.size()];
   QLabel *type[list.size()];
   QLabel *price[list.size()];
   QLabel *description[list.size()];
   QPushButton *details[list.size()];

   for(x=0;x < list.size(); x++){
         titles[x] = new QLabel(QString::fromUtf8(list.value(x).getTitle().c_str()));
         ui->itemGrid->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list.value(x).getType().c_str()));
         ui->itemGrid->addWidget(type[x],x+1,1,1,1);


         price[x] = new QLabel(QString::fromUtf8(list.value(x).getPrice().c_str()));
         ui->itemGrid->addWidget(price[x],x+1,2,1,1);


         description[x] = new QLabel(QString::fromUtf8(list.value(x).getDescription().c_str()));
         ui->itemGrid->addWidget(description[x],x+1,3,1,1);

         details[x] = new QPushButton("Details");
         ui->itemGrid->addWidget(details[x],x+1,4,1,1);

         mapper.append(new QSignalMapper());

         connect(details[x], SIGNAL(released()), mapper.value(x), SLOT(map()));
         mapper.value(x)->setMapping(details[x], x); // Number to be passed in the slot

         connect(mapper.value(x), SIGNAL(mapped(int)), this, SLOT(showDetails(int)));

   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->itemGrid->addItem(spacer,list.size(),4,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->itemGrid->addItem(vert,list.size()+1,0,1,0);

   ui->scrollArea->setStyleSheet("background-color:transparent;");
   ui->scrollAreaWidgetContents->setMinimumHeight(28*list.size()+1);

}
void CTMViewTextbooks::showDetails(int x){
    //Title,length,price,author,ISBN,course, description,type
     //OPtional->chapter->textbook
    Item showItem = items.value(x);

    ui->SelectedTitle->setText (QString::fromUtf8(showItem.getTitle().c_str()));
    ui->SelectedAuthor->setText(QString::fromUtf8(showItem.getAuthor().c_str()));
    ui->SelectedCourse->setText(QString::fromUtf8(showItem.getCourse().c_str()));
    ui->SelectedType->setText  (QString::fromUtf8(showItem.getType().c_str()));
    ui->SelectedISBN->setText  (QString::fromUtf8(showItem.getISBN().c_str()));
    ui->SelectedLength->setText(QString::fromUtf8(showItem.getLength().c_str()));
    ui->SelectedPrice->setText (QString::fromUtf8(showItem.getPrice().c_str()));
    ui->SelectedTexbook->setText ("");
    ui->SelectedChapter->setText("");
    ui->SelectedDescription->setText (QString::fromUtf8(showItem.getDescription().c_str()));
    if(showItem.getType()=="chapter"){
        Chapter *steveSucks = (Chapter*)&showItem;
        ui->SelectedTexbook->setText (QString::fromUtf8((steveSucks)->getTextbookName().c_str()));
    }
    if(showItem.getType()=="section"){
        section *steveSucks = (section*)&showItem;
        ui->SelectedTexbook->setText (QString::fromUtf8(steveSucks->getTextbookName().c_str()));
        ui->SelectedChapter->setText(QString::fromUtf8(steveSucks->getChapter().c_str()));
    }
}
