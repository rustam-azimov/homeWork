#ifndef TESTMYSET_H
#define TESTMYSET_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "mySet.h"

class TestMySet : public QObject
{
    Q_OBJECT
public:
    explicit TestMySet(QObject* parent = 0):
        QObject(parent)
    {}

private slots:
    void init()
    {
        testSet = new Set<int>;
    }

    void cleanup()
    {
        delete testSet;
    }

    void testCreate() {}

    void testIsEmpty()
    {
        QVERIFY(testSet->isEmpty());
    }

    void testAdd()
    {
        testSet->add(6);
        testSet->add(228);
        QVERIFY(!testSet->isEmpty());
    }

    void testRemove()
    {
        testSet->add(6);
        testSet->add(228);
        testSet->remove();
        QVERIFY(testSet->isEmpty());
    }

    void testIsContained()
    {
        QVERIFY(!testSet->isContained(6));
        testSet->add(6);
        testSet->add(12);
        QVERIFY(testSet->isContained(6));
        QVERIFY(testSet->isContained(12));
        QVERIFY(!testSet->isContained(228));
    }

    void testRemoveValue()
    {
        testSet->add(5);
        testSet->add(3);
        testSet->add(4);
        testSet->add(2);
        testSet->add(8);
        testSet->add(9);
        testSet->removeValue(8);
        testSet->removeValue(9);
        testSet->removeValue(3);
        testSet->removeValue(5);
        QVERIFY(!testSet->isContained(5));
        QVERIFY(!testSet->isContained(8));
        QVERIFY(!testSet->isContained(9));
        QVERIFY(!testSet->isContained(3));
    }

    void testCopy()
    {
        testSet->add(5);
        testSet->add(8);
        Set<int> *newSet = new Set<int>(testSet);
        QVERIFY(newSet->isContained(5));
        testSet->removeValue(5);
        QVERIFY(newSet->isContained(5));
    }

    void testIntersection()
    {
        testSet->add(5);
        testSet->add(3);
        testSet->add(4);
        testSet->add(2);
        Set<int> *setTwo = new Set<int>;
        setTwo->add(5);
        setTwo->add(2);
        setTwo->add(4);
        Set<int> *newSet = setTwo->intersection(testSet);
        QVERIFY(newSet->isContained(2));
        QVERIFY(!newSet->isContained(3));
        delete setTwo;
        delete newSet;
    }

    void testMerge()
    {
        testSet->add(5);
        testSet->add(3);
        testSet->add(4);
        testSet->add(2);
        Set<int> *setTwo = new Set<int>;
        setTwo->add(5);
        setTwo->add(1);
        setTwo->add(6);
        Set<int> *newSet = testSet->merge(setTwo);
        QVERIFY(newSet->isContained(3));
        QVERIFY(newSet->isContained(6));
        delete setTwo;
        delete newSet;
    }

private:
    Set<int> *testSet;
};

#endif // TESTMYSET_H
