#include "mainwindow.h"
#include <QApplication>
//#include "../Sources/Base/BaseGenerator.h"
#include "../Sources/GeneratorCPlusPlus.h"
#include "../Sources/Utilities.h"
//#include "../gtest/gtest.h"
//#include "../gmock/gmock.h"

/*double squareroot (const double x)
{
    return x*x;
}
*/

int main(int argc, char *argv[])
{

    //  ::testing::InitGoogleTest(&argc, argv);
    //  return RUN_ALL_TESTS();

    QApplication a(argc, argv);
    NGenerator::BaseGenerator* myGenerator = new NGenerator::GeneratorCPlusPlus();
    myGenerator->generate();
 //   MainWindow w;	

 //   w.show();
    delete myGenerator;
    return a.exec();
}

