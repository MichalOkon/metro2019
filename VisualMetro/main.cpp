#include "mainwindow.h"
#include "greetdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GreetDialog gD;
    gD.show();
//    MainWindow w;
//    w.show();

    return a.exec();
}
