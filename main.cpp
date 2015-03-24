#include "mainwindow.h"
#include <QApplication>
#include "PsnrClass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
   PsnrClass* videoUtil = new PsnrClass();
    return a.exec();
}
