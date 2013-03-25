#ifndef SORTETTEST_H
#define SORTETTEST_H

#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "quickSort.h"
#include "bubbleSort.h"
#include "dwarfSort.h"

class SorterTest : public QObject
{
    Q_OBJECT

 public:

   explicit SorterTest(QObject *parent = 0)
        : arraySize(15), QObject(parent) {}

private slots:
       void initTestCase()
       {
           array = new int[arraySize];
           for (int i = 0; i < arraySize; i++)
               array[i] = (rand() % 99) + 1;
           qTest = new QuickSort(array, arraySize);
           bTest = new BubbleSort(array, arraySize);
           hTest = new DwarfSort(array, arraySize);
       }

       void testQSort()
       {
           qTest->sort();
           int *sortedArray = qTest->returnArray();
           for (int i = 0; i < arraySize - 1; i++)
           {
               QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
           }
           delete[] sortedArray;
       }

       void testBSort()
       {
           bTest->sort();
           int *sortedArray = bTest->returnArray();
           for (int i = 0; i < arraySize - 1; i++)
           {
               QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
           }
           delete[] sortedArray;
       }

       void testHSort()
       {
           hTest->sort();
           int *sortedArray = hTest->returnArray();
           for (int i = 0; i < arraySize - 1; i++)
           {
               QVERIFY(sortedArray[i] <= sortedArray[i + 1]);
           }
           delete[] sortedArray;
       }

       void cleanupTestCase()
       {
           delete[] array;
           delete qTest;
           delete bTest;
           delete hTest;
       }

private:
       int const arraySize;
       int *array;
       Sorter *qTest;
       Sorter *bTest;
       Sorter *hTest;
   };
#endif // SORTETTEST_H
