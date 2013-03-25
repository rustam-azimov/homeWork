#ifndef HASHFUNCTIONTEST_H
#define HASHFUNCTIONTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "hashFunction.h"

class HashFunctionTest : public QObject
{
    Q_OBJECT
public:
    explicit HashFunctionTest(QObject *parent = 0):
        QObject(parent) {}
private slots:
    void init()
    {
        hashFunction = new HashFunction(101);
    }

    void cleanup()
    {
        delete hashFunction;
    }

    void testhashByModSize()
    {
        QVERIFY(hashFunction->hashByModSize(-102) == 100);
        QVERIFY(hashFunction->hashByModSize(59) == 59);
        QVERIFY(hashFunction->hashByModSize(1017) == 7);
    }

    void testHashByFunctionFamily()
    {
        QVERIFY(hashFunction->hashByFunctionFamily(-17) == 18);
        QVERIFY(hashFunction->hashByFunctionFamily(59) == 2);
    }

    void testHashByNumSum()
    {
        QVERIFY(hashFunction->hashByNumSum(-129) == 12);
        QVERIFY(hashFunction->hashByNumSum(11) == 2);
    }

private:
    HashFunction *hashFunction;
};

#endif // HASHFUNCTIONTEST_H
