#include <QCoreApplication>
#include "../../gtest/gtest.h"
#include "../../gmock/gmock.h"

#include "Basictest.h"
#include "functiontest.h"
#include "parsertest.h"
#include "classtest.h"

#include "systemtest.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
   // ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
    return a.exec();
}

