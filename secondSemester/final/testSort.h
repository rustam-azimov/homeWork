#ifndef TESTSORT_H
#define TESTSORT_H

#include <QObject>
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "bubbleSorter.h"

class TestSort : public QObject
{
    Q_OBJECT
public:
    explicit TestSort(QObject* parent = 0):
        QObject(parent),
        arraySize(10)
    {
        intArray = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            intArray[i] = i;
        }
        charArray = new char[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            charArray[i] = (char)((int)'0' + i);
        }
    }

private slots:
    void init()
    {
        intSorter = new BubbleSorter<int>;
        charSorter = new BubbleSorter<char>;
    }

    void cleanup()
    {
        delete intSorter;
    }

    void testCreate() {}

    void testIntSort()
    {
        IntCompare compare;
        for (int i = 0; i < arraySize - 1; i++)
        {
            QVERIFY(intArray[i] < intArray[i + 1]);
        }

        intSorter->sort(intArray, arraySize, compare);

        for (int i = 0; i < arraySize - 1; i++)
        {
            QVERIFY(intArray[i] >= intArray[i + 1]);
        }
    }

    void testCharSort()
    {
        CharCompare compare;
        for (int i = 0; i < arraySize - 1; i++)
        {
            QVERIFY(charArray[i] < charArray[i + 1]);
        }

        charSorter->sort(charArray, arraySize, compare);

        for (int i = 0; i < arraySize - 1; i++)
        {
            QVERIFY(charArray[i] >= charArray[i + 1]);
        }
    }

private:
    class IntCompare
    {
    public:
        bool operator() (const int &a, const int &b)
        {
            return (a < b);
        }
    };

    class CharCompare
    {
    public:
        bool operator ()(const char &c1, const char &c2)
        {
            return (c1 < c2);
        }
    };

private:
    int arraySize;

    BubbleSorter<int> *intSorter;
    int *intArray;

    BubbleSorter<char> *charSorter;
    char *charArray;
};

#endif // TESTSORT_H
