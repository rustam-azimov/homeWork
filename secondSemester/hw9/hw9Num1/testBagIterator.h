#ifndef TESTBAGITERATOR_H
#define TESTBAGITERATOR_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "bag.h"

class TestBagIterator : public QObject
{
    Q_OBJECT
public:
    explicit TestBagIterator(QObject *parent = 0):
        QObject(parent)
    {}

private:
    Bag<int> *bag;
    
private slots:

    void init()
    {
        bag = new Bag<int>();
    }

    void cleanup()
    {
        delete bag;
    }

    void testCreate()
    {
        Bag<int>::Iterator iterator(bag);
    }

    void testHasNext()
    {
        bag->add(10);
        bag->add(5);
        bag->add(15);
        Bag<int>::Iterator iterator(bag);
        QVERIFY(iterator.hasNext());
    }

    void testNext()
    {
        bag->add(10);
        bag->add(5);
        bag->add(15);
        Bag<int>::Iterator iterator(bag);
        QCOMPARE(iterator.next(), 5);
        QCOMPARE(iterator.next(), 10);
        QCOMPARE(iterator.next(), 15);
    }

    void testIteratorAdd()
    {
        bag->add(10);
        bag->add(5);
        bag->add(15);
        Bag<int>::Iterator iterator(bag);
        iterator.next();
        iterator.add(7);
        QCOMPARE(iterator.next(), 10);
        iterator.add(16);
        QCOMPARE(iterator.next(), 15);
        QVERIFY(!iterator.hasNext());
        QCOMPARE(iterator.next(), 16);

        QVERIFY(bag->isContained(7));
        QVERIFY(bag->isContained(16));
    }

    void testIteratorRemove()
    {
        bag->add(10);
        bag->add(5);
        bag->add(15);
        Bag<int>::Iterator iterator(bag);
        iterator.remove();
        QCOMPARE(iterator.next(), 10);
        QVERIFY(!bag->isContained(5));
        iterator.remove();
        QCOMPARE(iterator.next(), 10);
        QVERIFY(!bag->isContained(15));
    }
};

#endif // TESTBAGITERATOR_H
