#include "mainwindow.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);   
    MainWindow w;
    w.show();
    QCoreApplication::setOrganizationName("Brno University of Technology");
    QCoreApplication::setApplicationName("VideoCodecs");
    QSettings settings;
    settings.remove("encode/height");
    settings.remove("encode/width");
    settings.remove("test/width");
    settings.remove("test/height");
    settings.remove("test/frames");

    return a.exec();



}
