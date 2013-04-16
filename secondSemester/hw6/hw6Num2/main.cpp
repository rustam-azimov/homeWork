#include <QtCore/QCoreApplication>
#include "testMySet.h"

/**
 * @file main.cpp
 *
 * Program to work with set.
 * Contains implementation of container class Set and tests.
 */

int main()
{
    TestMySet test;
    QTest::qExec(&test);
    return 0;
}
