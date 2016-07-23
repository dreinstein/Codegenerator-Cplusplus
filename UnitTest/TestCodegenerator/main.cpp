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
<<<<<<< HEAD
  //  ::testing::InitGoogleMock(&argc, argv);
  //  return RUN_ALL_TESTS();
=======
   // ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
>>>>>>> 618d634f63e5dd5825ea52938773046db73a0a1c
    return a.exec();
}

