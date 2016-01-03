#include "mainwindow.h"
#include <QApplication>
//#include "../Sources/Base/BaseGenerator.h"
#include "../Sources/GeneratorCPlusPlus.h"
#include "../Sources/Utilities.h"
//#include "../gtest/gtest.h"
//#include "../gmock/gmock.h"
#include <QString>

/*double squareroot (const double x)
{
    return x*x;
}
*/

int main(int argc, char *argv[])
{

    //  ::testing::InitGoogleTest(&argc, argv);
    //  return RUN_ALL_TESTS();
    QString scriptTogenerate = "c:\\Codegenerator\\Scripts\\myFirstScript.txt";
   // QString cPulsPlusRules = "c:\\Codegenerator\\Keywords\\myFirstKeywords.txt";
//    QString scriptTogenerate = "c:\\Codegenerator\\Scripts\\myFirstScript.txt";
    QApplication a(argc, argv);
    NGenerator::BaseGenerator* myGenerator = new NGenerator::GeneratorCPlusPlus(scriptTogenerate);
    myGenerator->generate();
 //   MainWindow w;	

 //   w.show();
    delete myGenerator;
    return a.exec();
}

