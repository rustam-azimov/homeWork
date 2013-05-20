#include <QtCore/QCoreApplication>
#include "testBag.h"

/**
 * @file main.cpp
 *
 * Program to work with multi-set.
 * Contains implementation of container class Set and tests.
 */

int main()
{
    TestBag test;
    QTest::qExec(&test);
    return 0;
}
