#include "parsertest.h"
#include "../../gtest/gtest.h"
//#include "../../gmock/gmock.h"
#include "Parserimplementation.h"

ParserTest::ParserTest()
{
    ParserImpl *parser = new ParserImpl();
    delete parser;
}

