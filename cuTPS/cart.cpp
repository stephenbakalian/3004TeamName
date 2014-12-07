#include "cart.h"
#include "ui_cart.h"
#include "mainwindow.h"
Cart::Cart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Cart)
{
    ui->setupUi(this);
}

Cart::~Cart()
{
    delete ui;
}

void Cart::setUsername(std::string user){
    username=user;
    updateUI();
}

void Cart::updateUI(){

    Item *temp1 = new Item();
    Item *temp2 = new Item();
    Item *temp3 = new Item();
    Item *temp4 = new Item();

    temp1->setTitle("HOW TO WIN at chess");
    temp2->setTitle("Batman beyond");
    temp3->setTitle("duck you");
    temp4->setTitle("Hai");

    /**
      HERE ITEMS SHOULD BE GRABBED FROM SERVER
     **/

    reqHandler = new RequestHandler(this);
    QList<Item> items;

    items = reqHandler->viewCart(username);
    Item literature[items.size()+1];
    qDebug()<<items.size();
    for (int i =0; i < items.size(); i++){
        literature[i] = items.value(i);
    }

    showItems(literature);

}

void Cart::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}

void Cart::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems(username);

}
void Cart::showItems(Item list[]){
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

void Cart::on_pushButton_3_clicked()
{
    reqHandler = new RequestHandler(this);

    //TODO cart items here
    Item item;
    item.setTitle("test");
    QList<Item> cartItems;
    cartItems.push_back(item);
    //TODO ends here

    int resp = reqHandler->checkout(cartItems, username);

    qDebug() << "purchase cart" << resp;

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


