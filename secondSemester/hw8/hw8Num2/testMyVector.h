#ifndef TESTMYVECTOR_H
#define TESTMYVECTOR_H

#include <QObject>
#include <QtTest/QtTest>
#include "myVector.h"

class TestMyVector : public QObject
{
Q_OBJECT

private slots:

    void init()
    {
        myVector = new MyVector(5);
    }

    void testCreate(){}

    void testIsZero()
    {
        QVERIFY(myVector->isZeroVector());
    }

    void testSetValue()
    {
        myVector->setValueAtPosition(10, 2);
        QVERIFY(!myVector->isZeroVector());
    }

    void testValueAt()
    {
        myVector->setValueAtPosition(10, 2);
        QVERIFY(myVector->valueAtPosition(2) == 10);
    }

    void testAddition()
    {
        myVector->setValueAtPosition(10, 2);
        myVector->setValueAtPosition(-5, 3);
        MyVector otherVector(*myVector);
        (*myVector) += otherVector;
        QVERIFY(myVector->valueAtPosition(2) == 20);
        QVERIFY(myVector->valueAtPosition(3) == -10);
    }

    void testSubtraction()
    {
        myVector->setValueAtPosition(10, 2);
        myVector->setValueAtPosition(-5, 3);
        MyVector otherVector(*myVector);
        (*myVector) -= otherVector;
        QVERIFY(myVector->isZeroVector());
    }

    void testMultiplication()
    {
        myVector->setValueAtPosition(10, 2);
        myVector->setValueAtPosition(-5, 3);
        MyVector otherVector(*myVector);
        QVERIFY(((*myVector) * otherVector == 125));
    }

    void cleanup()
    {
        delete myVector;
    }

private:
    MyVector* myVector;
};

#endif // TESTMYVECTOR_H
