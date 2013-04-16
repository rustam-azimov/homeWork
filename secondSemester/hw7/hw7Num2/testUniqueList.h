#ifndef TESTUNIQUELIST_H
#define TESTUNIQUELIST_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "uniqueList.h"

class TestUniqueList : public QObject
{
    Q_OBJECT
public:
    explicit TestUniqueList(QObject* parent = 0):
        QObject(parent)
    {}

private slots:
    void init()
    {
        testList = new UniqueList<int>;
    }

    void cleanup()
    {
        delete testList;
    }

    void testCreate() {}

    void testIsEmpty()
    {
        QVERIFY(testList->isEmpty());
    }

    void testAdd()
    {
        testList->addInPos(3, 5);
    }

    void testIsContained()
    {
        testList->addInPos(3, 5);
        testList->addInPos(1, 2);
        QVERIFY(testList->isContained(1));
        QVERIFY(testList->isContained(3));
        QVERIFY(!testList->isContained(5));
    }

    void testAddFirst()
    {
        testList->addFirst(5);
    }

    void testAddLast()
    {
        testList->addLast(3);
    }

    void testIsEmptyAfterAdd()
    {
        testList->addInPos(5, 2);
        QVERIFY(!testList->isEmpty());
    }

    void testLength()
    {
        testList->addFirst(3);
        testList->addFirst(2);
        testList->addFirst(15);
        QVERIFY(testList->getLength() == 3);
    }

    void testAddThrow()
    {
        testList->addFirst(5);
        try
        {
            testList->addFirst(5);
            QVERIFY(false);
        }
        catch(uniqueListException::NoSuchValue const &)
        {
            QVERIFY(false);
        }
        catch(uniqueListException::NotUniqueValue const &)
        {
            QVERIFY(true);
        }
    }

    void testRemoveThrow()
    {
        testList->addFirst(5);
        try
        {
            testList->removeValue(12);
            QVERIFY(false);
        }
        catch(uniqueListException::NoSuchValue const &)
        {
            QVERIFY(true);
        }
        catch(uniqueListException::NotUniqueValue const &)
        {
            QVERIFY(false);
        }
    }

private:
    UniqueList<int> *testList;
};



#endif // TESTUNIQUELIST_H
