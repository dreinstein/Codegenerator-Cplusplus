#include "mainwindow.h"
#include <QApplication>
#include "../Sources/BaseGenerator.h"
#include "../Sources/GeneratorCPlusPlus.h"
#include "../Sources/Utilities.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NGenerator::BaseGenerator* myGenerator = new NGenerator::GeneratorCPlusPlus();
    myGenerator->generate();
 //   MainWindow w;	

 //   w.show();
    delete myGenerator;
    return a.exec();
}
