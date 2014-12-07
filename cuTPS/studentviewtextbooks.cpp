#include "studentviewtextbooks.h"
#include "ui_studentviewtextbooks.h"
#include "mainwindow.h"

StudentViewTextbooks::StudentViewTextbooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentViewTextbooks)
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

StudentViewTextbooks::~StudentViewTextbooks()
{
    delete ui;
}

void StudentViewTextbooks::setUsername(std::string user){
    username=user;
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
    std::string checkedItems[4];
    checkedItems[1]="waffles";
    //TODO ends here

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
void StudentViewTextbooks::showItems(Item list[]){
   //ui->gridLayout
   int x;
   QLabel *titles[sizeof(list)];
   QLabel *type[sizeof(list)];
   QLabel *price[sizeof(list)];
   QLabel *description[sizeof(list)];
   QPushButton *details[sizeof(list)];
   QCheckBox *addToCart[sizeof(list)];



   for(x=0;x < sizeof(list); x++){
         titles[x] = new QLabel(QString::fromUtf8(list[x].getTitle().c_str()));
         ui->gridLayout->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list[x].getType().c_str()));
         ui->gridLayout->addWidget(type[x],x+1,1,1,1);


         price[x] = new QLabel(QString::fromUtf8(list[x].getPrice().c_str()));
         ui->gridLayout->addWidget(price[x],x+1,2,1,1);

         addToCart[x] = new QCheckBox("");
         ui->gridLayout->addWidget(addToCart[x],x+1,3,1,1);


         description[x] = new QLabel(QString::fromUtf8(list[x].getDescription().c_str()));
         ui->gridLayout->addWidget(description[x],x+1,4,1,1);

         details[x] = new QPushButton("Details");
         ui->gridLayout->addWidget(details[x],x+1,5,1,1);




   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->gridLayout->addItem(spacer,sizeof(list),5,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->gridLayout->addItem(vert,sizeof(list)+1,0,1,0);
}

