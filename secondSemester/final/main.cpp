#include <QtCore/QCoreApplication>
#include "testSort.h"

/**
 * @file main.cpp
 *
 * Program to sort tamplate array by use the Bubble Sort.
 */

int main()
{
    TestSort test;
    QTest::qExec(&test);
    return 0;
}
