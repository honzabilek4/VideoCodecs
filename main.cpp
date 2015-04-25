#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    MainWindow w;
    w.show();
    QCoreApplication::setOrganizationName("Brno University of Technology");
    QCoreApplication::setApplicationName("VideoCodecs");
    return a.exec();



}
