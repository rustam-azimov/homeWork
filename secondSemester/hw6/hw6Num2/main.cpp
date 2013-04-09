#include <QtCore/QCoreApplication>
#include "testBinaryTree.h"

int main()
{
    TestBinaryTree test;
    QTest::qExec(&test);
    return 0;
}
