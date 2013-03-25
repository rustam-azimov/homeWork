#include <QtCore/QCoreApplication>

#include "userInterface.h"

#include "hasherTest.h"
#include "hashFunctionTest.h"

/**
* @file main.cpp
*
* @section DESCRIPTION
*
* Program to work with hash-tables.
* You can use various hash-functions, to fill the table.
*/

int main()
{

HasherTest test1;
QTest::qExec(&test1);
HashFunctionTest test2;
QTest::qExec(&test2);

    work();

    return 0;
}
