#include "homescreen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HomeScreen w;

    w.show();
//    if (!w.createConnection()){
//        return 1;
//    }

    return a.exec();
}
