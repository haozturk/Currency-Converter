#include <QtGui>
#include "myclass.h"
#include <QRegExp>
#include <QHBoxLayout>
#include "ui_myclass.h"
#include <iostream>
#include <string>

using namespace  std;

MyClass::MyClass(QWidget *parent) : QMainWindow(parent),ui(new Ui::MyClass)//QLabel(parent)
{

    ui->setupUi(this); //User interface is created, it is configured afterwards

    manager = new QNetworkAccessManager(this) ; //manager objects controls the network flow

    //when signal is taken from manager object, replyFinished function executed through the MyClass object
    connect(manager, SIGNAL(finished(QNetworkReply *)),this, SLOT(replyFinished(QNetworkReply *)));

    // Initiate retrieval of  the data from the web page.
    // When completed, slot replyFinished will be called.
    manager->get(QNetworkRequest(QUrl("https://api.fixer.io/latest?base=TRY")));

}

void MyClass::replyFinished(QNetworkReply *reply)  {

    int pos = 0;

    // read the data fetched from the web site
    QString data = (QString) reply->readAll();


    // use pattern matching to extract the rate for each currency
    QRegExp rxUSD("((USD\":(\\d+\\.\\d+)))");
    QRegExp rxEUR("((EUR\":(\\d+\\.\\d+)))");
    QRegExp rxGBP("((GBP\":(\\d+\\.\\d+)))");
    QRegExp rxCNY("((CNY\":(\\d+\\.\\d+)))");


    if ( rxUSD.indexIn(data, pos) != -1 ) {
        strUSD = rxUSD.cap(3);    // rate found
    }
    else {
        strUSD = QString("Error") ;
    }

    if ( rxEUR.indexIn(data, pos) != -1 ) {
        strEUR = rxEUR.cap(3);    // rate found
    }
    else {
        strEUR = QString("Error") ;
    }

    if ( rxGBP.indexIn(data, pos) != -1 ) {
        strGBP =  rxGBP.cap(3);    // rate found
    }
    else {
        strGBP = QString("Error") ;
    }

    if ( rxCNY.indexIn(data, pos) != -1 ) {
        strCNY = rxCNY.cap(3);    // rate found
    }
    else {
        strCNY = QString("Error") ;
    }

}

void MyClass::on_usdButton_clicked()
{
    ui->rateLine->setText(strUSD + " TL/USD"); //line edit of rate row is configured

    QRegExp rx1("[^tlTL ]+"); //pattern which determines the amount that will be converted
    QString myString;
    if ( rx1.indexIn(ui->tlLine->text(), 0) != -1 ) {
        myString = rx1.cap();    // rate found
    }
    double tlValue = myString.toDouble(); //string value of TL amount is converted into double
    double rate = strUSD.toDouble(); //rate is converted into double
    double b = (rate*tlValue); //corresponding usd amount is calculated
    QString abc = QString::number(b); //usd amount is converted into string
    ui->amountLine->setText(abc + " USD"); // it is put into the line edit section

}

void MyClass::on_eurButton_clicked()
{
    ui->rateLine->setText(strEUR + " TL/EUR" );

    QRegExp rx1("[^tlTL ]+"); //pattern which determines the amount that will be converted
    QString myString;
    if ( rx1.indexIn(ui->tlLine->text(), 0) != -1 ) {
        myString = rx1.cap();    // rate found
    }
    double tlValue = myString.toDouble(); //string value of TL amount is converted into double
    double rate = strEUR.toDouble(); //rate is converted into double
    double b = (rate*tlValue); //corresponding euro amount is calculated
    QString abc = QString::number(b); //euro amount is converted into string
    ui->amountLine->setText(abc + " EUR"); // it is put into the line edit section
}

void MyClass::on_gbpButton_clicked()
{
    ui->rateLine->setText(strGBP + " TL/GBP");

    QRegExp rx1("[^tlTL ]+"); //pattern which determines the amount that will be converted
    QString myString;
    if ( rx1.indexIn(ui->tlLine->text(), 0) != -1 ) {
        myString = rx1.cap();    // rate found
    }
    double tlValue = myString.toDouble(); //string value of TL amount is converted into double
    double rate = strGBP.toDouble(); //rate is converted into double
    double b = (rate*tlValue); //corresponding gdp amount is calculated
    QString abc = QString::number(b); //gdp amount is converted into string
    ui->amountLine->setText(abc + " GBP"); // it is put into the line edit section
}

void MyClass::on_cnyButton_clicked()
{
    ui->rateLine->setText(strCNY + " TL/CNY");

    QRegExp rx1("[^tlTL ]+"); //pattern which determines the amount that will be converted
    QString myString;
    if ( rx1.indexIn(ui->tlLine->text(), 0) != -1 ) {
        myString = rx1.cap();    // rate found
    }
    double tlValue = myString.toDouble(); //string value of TL amount is converted into double
    double rate = strCNY.toDouble(); //rate is converted into double
    double b = (rate*tlValue); //corresponding cny amount is calculated
    QString abc = QString::number(b); //cny amount is converted into string
    ui->amountLine->setText(abc + " CNY"); // it is put into the line edit section
}
