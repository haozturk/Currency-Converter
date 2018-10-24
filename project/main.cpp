#include <QtCore>
#include <QApplication>
#include "myclass.h"

int main(int argc,char *argv[])
{
   QApplication a(argc, argv); //controls the gui in background
   MyClass my ; //the object that has the needed functions and fields

   my.show(); //make the program visible by user

   return a.exec();
}
