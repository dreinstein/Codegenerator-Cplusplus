#include <QCoreApplication>
#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"
#include "parsertest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::InitGoogleMock(&argc, argv);
   // ParserTest* parser = new ParserTest();
    return RUN_ALL_TESTS();
  //  delete parser;
    return a.exec();
}

