#include "mainwindow.h"
#include <QApplication>
//#include "../Sources/Base/BaseGenerator.h"
#include "../Sources/GeneratorCPlusPlus.h"
#include "../Sources/Utilities.h"
//#include "../gtest/gtest.h"
//#include "../gmock/gmock.h"
#include <QString>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();

    return app.exec();

   // QString scriptTogenerate = "c:\\Codegenerator\\Scripts\\myFirstScript.txt";
   // QString cPulsPlusRules = "c:\\Codegenerator\\Keywords\\myFirstKeywords.txt";
//    QString scriptTogenerate = "c:\\Codegenerator\\Scripts\\myFirstScript.txt";
   // QApplication a(argc, argv);
   // NGenerator::BaseGenerator* myGenerator = new NGenerator::GeneratorCPlusPlus(scriptTogenerate);
   // myGenerator->generate();

    //delete myGenerator;
    //return a.exec();
}

