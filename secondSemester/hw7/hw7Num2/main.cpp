#include <QtCore/QCoreApplication>
#include "testUniqueList.h"

/**
 * @file main.cpp
 *
 * Program to work with linked list, contained only unique values.
 * Contains implementation of container class UniqueList and tests.
 */

int main()
{
    TestUniqueList test;
    QTest::qExec(&test);
    return 0;
}

