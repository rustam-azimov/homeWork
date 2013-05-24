#include <QtCore/QCoreApplication>
#include "testBag.h"
#include "testBagIterator.h"

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

    TestBagIterator testIter;
    QTest::qExec(&testIter);
    return 0;
}
