#ifndef HASHERTEST_H
#define HASHERTEST_H

#include <QObject>
#include <QtTest/QtTest>
#include "hasher.h"

class HasherTest : public QObject
{
    Q_OBJECT
public:
    explicit HasherTest(QObject *parent = 0):
        QObject(parent) {}

private slots:
    void init()
    {
        hash = new Hasher;
    }

    void testCalcHash()
    {
        QVERIFY(hash->calcHash(228) == 26);
    }

    void testChangeHash()
    {
        hash->changeHash(bySum);
        QVERIFY(hash->calcHash(35) == 8);
        hash->changeHash(byFam);
        QVERIFY(hash->calcHash(1) == 78);
    }

    void testAdd()
    {
        hash->addToHash(-19);
        hash->addToHash(101);
        hash->addToHash(0);
    }

    void testContained()
    {
        hash->addToHash(-19);
        hash->addToHash(101);
        QVERIFY(hash->isContained(-19));
        QVERIFY(hash->isContained(101));
        QVERIFY(!hash->isContained(22));
    }


    void testRemove()
    {
        hash->addToHash(-19);
        hash->addToHash(101);
        hash->addToHash(15);
        hash->removeFromHash(101);
        hash->removeFromHash(15);
        hash->removeFromHash(228);
    }

    void testRemoveAndIsContained()
    {
        hash->addToHash(-19);
        QVERIFY(hash->isContained(-19));
        hash->removeFromHash(-19);
        QVERIFY(!hash->isContained(-19));
    }

    void testRehash()
    {
        for (int i = 0; i < 20; i++)
            hash->addToHash(rand() % 20);
        hash->addToHash(99);
        hash->rehash(bySum);
        QVERIFY(hash->isContained(99));
        QVERIFY(hash->calcHash(99) == 18);
    }


    void cleanup()
    {
        delete hash;
    }

private:
    Hasher *hash;
};

#endif // HASHERTEST_H
