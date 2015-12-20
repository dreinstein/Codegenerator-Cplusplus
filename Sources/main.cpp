#include "mainwindow.h"
#include <QApplication>
#include "../Sources/BaseGenerator.h"
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

/*TEST (SquareRootTest, PositiveNos) {
    EXPECT_EQ (18.0, squareroot (324.0));
    EXPECT_EQ (25.4, squareroot (645.16));
    EXPECT_EQ (50.3321, squareroot (2533.310224));
}*/

