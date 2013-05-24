#ifndef TESTBAG_H
#define TESTBAG_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "Bag.h"

class TestBag : public QObject
{
    Q_OBJECT
public:
    explicit TestBag(QObject* parent = 0):
        QObject(parent)
    {}

private slots:
    void init()
    {
        testBag = new Bag<int>;
    }

    void cleanup()
    {
        delete testBag;
    }

    void testCreate()
    {
        QCOMPARE(testBag->elementsCount(), 0);
    }

    void testIsEmpty()
    {
        QVERIFY(testBag->isEmpty());
    }

    void testAdd()
    {
        testBag->add(6);
        testBag->add(228);
        QVERIFY(!testBag->isEmpty());
    }

    void testRemove()
    {
        testBag->add(6);
        testBag->add(228);
        testBag->remove();
        QVERIFY(testBag->isEmpty());
    }

    void testIsContained()
    {
        QVERIFY(!testBag->isContained(6));
        testBag->add(6);
        testBag->add(12);
        QVERIFY(testBag->isContained(6));
        QVERIFY(testBag->isContained(12));
        QVERIFY(!testBag->isContained(228));
        testBag->remove();
        QVERIFY(!testBag->isContained(6));
    }

    void testElementMultiplicity()
    {
        QVERIFY(!testBag->elementMultiplicity(6));
        testBag->add(6);
        testBag->add(6);
        testBag->add(12);
        QCOMPARE(testBag->elementMultiplicity(6), 2);
        QCOMPARE(testBag->elementMultiplicity(12), 1);
    }

    void testRemoveValue()
    {
        testBag->add(5);
        testBag->add(5);
        testBag->add(4);
        testBag->add(2);
        QVERIFY(testBag->elementsCount() == 4);
        testBag->add(8);
        testBag->add(9);
        testBag->removeValue(8);
        testBag->removeValue(9);
        testBag->removeValue(3);
        testBag->removeValue(5);
        QCOMPARE(testBag->elementsCount(), 3);
        QCOMPARE(testBag->isContained(5), 1);
        QVERIFY(!testBag->isContained(8));
        QVERIFY(!testBag->isContained(9));
        QVERIFY(!testBag->isContained(3));
    }


private:
    Bag<int> *testBag;
};

#endif // TESTBAG_H
