#include "cart.h"
#include "ui_cart.h"
#include <sstream>
#include "mainwindow.h"



#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
/**
 * Page used to represent and display the users cart
 *
 * @brief Cart::Cart
 * @param parent
 */
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
//set the username of the user on this page
void Cart::setUsername(std::string user){
    username=user;
    updateUI();
}
//this updates the ui, it getsthe list from the server then displays
void Cart::updateUI(){

    reqHandler = new RequestHandler(this);
    QList<Item> items;

    items = reqHandler->viewCart(username);


    showItems(items);

}
//Logout button is press -> send to login page
void Cart::on_pushButton_clicked()
{
    ((MainWindow*)parentWidget())->setViewLogin();

}
//Go to all List button pressed
void Cart::on_pushButton_2_clicked()
{
    ((MainWindow*)parentWidget())->setStuViewItems(username);

}
//called to show a set of items
void Cart::showItems(QList<Item> list){
   //ui->gridLayout
   int x;
   allList=list;
   QLabel *titles[list.size()];
   QLabel *type[list.size()];
   QLabel *price[list.size()];
   QLabel *purchaseDate[list.size()];
   double totalPrice=0;
   for(x=0;x < list.size(); x++){
         titles[x] = new QLabel(QString::fromUtf8(list.value(x).getTitle().c_str()));
         ui->gridLayout->addWidget(titles[x],x+1,0,1,1);

         type[x] = new QLabel(QString::fromUtf8(list.value(x).getType().c_str()));
         ui->gridLayout->addWidget(type[x],x+1,1,1,1);

         price[x] = new QLabel(QString::fromUtf8(list.value(x).getPrice().c_str()));
         ui->gridLayout->addWidget(price[x],x+1,3,1,1);

         purchaseDate[x] = new QLabel(QString::fromUtf8(list.value(x).getPurchaseDate().c_str()));
         ui->gridLayout->addWidget(purchaseDate[x],x+1,3,1,1);

         totalPrice+= atoi(list.value(x).getPrice().c_str());
   }
   QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Expanding, QSizePolicy::Maximum);
   ui->gridLayout->addItem(spacer,list.size(),5,1,1);

   QSpacerItem *vert = new QSpacerItem(1, 1000, QSizePolicy::Expanding, QSizePolicy::Minimum);
   ui->gridLayout->addItem(vert,list.size()+1,0,1,0);

   ui->scrollArea->setStyleSheet("background-color:transparent;");
   ui->totalPrice->setText((SSTR(totalPrice)).c_str());
   ui->scrollAreaWidgetContents->setMinimumHeight(28*list.size()+1);
}
//purchase cart pressed -> send request to server, update-> return to view list
void Cart::on_pushButton_3_clicked()
{
    reqHandler = new RequestHandler(this);

    //TODO cart items here

    //TODO ends here

    int resp = reqHandler->checkout(allList, username);

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


//empty cart => send request to server ->returns to textbook list view
void Cart::on_pushButton_4_clicked()
{//empty the cart
    reqHandler = new RequestHandler(this);

    Item item;
    item.setTitle("test");
    QList<Item> cartItems;
    cartItems.push_back(item);

    int resp = reqHandler->emptyCart(username);

    qDebug() << "empty cart" << resp;

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
    }
    ((MainWindow*)parentWidget())->setStuViewItems(username);
}
