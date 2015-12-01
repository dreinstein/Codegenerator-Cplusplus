#include "mainwindow.h"
#include <QApplication>
#include "../Sources/Generator.h"
#include "../Sources/Utilities.h"

using namespace Logic;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Generator* myGenerator = new Generator();
    myGenerator->generate();
 //   MainWindow w;	

 //   w.show();
    delete myGenerator;
    return a.exec();
}
