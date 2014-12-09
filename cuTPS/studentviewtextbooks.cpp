#include "studentviewtextbooks.h"
#include "ui_studentviewtextbooks.h"
#include "mainwindow.h"
#include <QDebug>

StudentViewTextbooks::StudentViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentViewTextbooks)
{
    ui->setupUi(this);
}

StudentViewTextbooks::~StudentViewTextbooks()
{
    delete ui;
}

void StudentViewTextbooks::setUsername(std::string user){
    username=user;
    updateUI();
}

void StudentViewTextbooks::updateUI(){
    reqHandler = new RequestHandler(this);


    items = reqHandler->getStuCourseLoad(username);

    showItems(items);
}

void StudentViewTextbooks::on_pushButton_6_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}

void StudentViewTextbooks::on_pushButton_7_clicked()
{
    ((MainWindow*)parentWidget())->setViewCart(username);
}

void StudentViewTextbooks::on_pushButton_8_clicked()
{
    ((MainWindow*)parentWidget())->setViewOwnedItems(username);
}

void StudentViewTextbooks::on_pushButton_5_clicked()
{
    reqHandler = new RequestHandler(this);

    //TODO loop seleteditems
    QList<Item> checkedItems;
    //TODO ends here
    for(int x=0; x<items.size();x++){
        if(addToCart.value(x)->isChecked()){
            checkedItems.push_back(items.value(x));
        }
    }

    int resp = reqHandler->AddToCart(checkedItems, username);

    qDebug() << "Add to cart" << resp;
    switch (resp) {
    case -5:
        ((MainWindow*)parentWidget())->setViewError("Database connection error",1, username);
        break;
    case -4:
        ((MainWindow*)parentWidget())->setViewError("Unable to connect to the server... \n is it running?",0, username);
        break;
    case -3:
        ((MainWindow*)parentWidget())->setViewError("Opps/nSomething went very wrong",1, username);
        break;
    case -2:
        ((MainWindow*)parentWidget())->setViewError("Unknown Json Parsing Error",1,username);
        break;
    case 0://Socket Disconect
        break;
    case 1: //Successfull
        break;
    case 2: //Student logs in
        //Add to cart
        break;
    default:
        ((MainWindow*)parentWidget())->setViewError("An unhandeled error occured \n please contant a techincal assiant \n ERROR: " + resp,1, username);
    }
}
void StudentViewTextbooks::showItems(QList<Item> list){
   //ui->gridLayout
   int x;
   QLabel *titles[list.size()];
   QLabel *type[list.size()];
   QLabel *price[list.size()];
   QLabel *description[list.size()];
   QPushButton *details[list.size()];


   for(x=0;x < list.size(); x++){
         qDebug() << QString::fromUtf8(list[x].getTitle().c_str());
         titles[x] = new QLabel(QString::fromUtf8(list.value(x).getTitle().c_str()));
         ui->gridLayout->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list.value(x).getType().c_str()));
         ui->gridLayout->addWidget(type[x],x+1,1,1,1);


         price[x] = new QLabel(QString::fromUtf8(list.value(x).getPrice().c_str()));
         ui->gridLayout->addWidget(price[x],x+1,2,1,1);

         addToCart.append(new QCheckBox(""));
         ui->gridLayout->addWidget(addToCart.value(x),x+1,3,1,1);


         description[x] = new QLabel(QString::fromUtf8(list.value(x).getDescription().c_str()));
         ui->gridLayout->addWidget(description[x],x+1,4,1,1);

         details[x] = new QPushButton("Details");
         ui->gridLayout->addWidget(details[x],x+1,5,1,1);

         mapper.append(new QSignalMapper());

         connect(details[x], SIGNAL(released()), mapper.value(x), SLOT(map()));
         mapper.value(x)->setMapping(details[x], x); // Number to be passed in the slot

         connect(mapper.value(x), SIGNAL(mapped(int)), this, SLOT(showDetails(int)));
   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->gridLayout->addItem(spacer,list.size(),5,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->gridLayout->addItem(vert,list.size()+1,0,1,0);

   ui->scrollAreaWidgetContents->setMaximumHeight(28*list.size()+1);
   ui->scrollArea->setStyleSheet("background-color:transparent;");



}

//TODO: UPDATE SECTION AND CHAPTER AREAS TO CAST AN USE INHERITED FUNCTIONS
void StudentViewTextbooks::showDetails(int x){
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
    ui->SelectedDescription->setText (QString::fromUtf8(showItem.getDescription().c_str()));
    ui->SelectedTexbook->setText ("");
    ui->SelectedChapter->setText("");
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

