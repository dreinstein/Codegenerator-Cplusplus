#include "mainwindow.h"
#include <QApplication>
#include "../Sources/GeneratorCPlusPlus.h"
#include "../Sources/BaseGenerator.h"
#include "../Sources/Utilities.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BaseGenerator* myGenerator = new GeneratorCPlusPlus();
    myGenerator->generate();
 //   MainWindow w;	

 //   w.show();
    delete myGenerator;
    return a.exec();
}
