#ifndef MYCLASS_H
#define MYCLASS_H


#include <QtGui>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QLabel>
#include <QMainWindow>

namespace Ui {
class MyClass;
}

//The constructor which takes a QMainWindow object that provides the graphical layout
class MyClass : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyClass(QWidget *parent = 0);
    QString strUSD;  //USD rate fetched from the desired website in string form
    QString strEUR;  //EUR rate fetched from the desired website in string form
    QString strGBP;  //GBP rate fetched from the desired website in string form
    QString strCNY;  //CNY rate fetched from the desired website in string form


public slots:
    //The function that takes the data from the website and edits it with regex
    void replyFinished(QNetworkReply * reply) ;

private slots:
    void on_usdButton_clicked(); //function that determines what to do when clicked into USD button

    void on_eurButton_clicked(); //function that determines what to do when clicked into EUR button

    void on_gbpButton_clicked(); //function that determines what to do when clicked into GBP button

    void on_cnyButton_clicked(); //function that determines what to do when clicked into CNY button

private:
    QNetworkAccessManager *manager ; //The object that handles fetching the data from web
    Ui::MyClass *ui; //user interface that interacts with user via graphical panel
} ;


#endif // MYCLASS_H

