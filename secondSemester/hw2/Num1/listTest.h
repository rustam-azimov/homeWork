#ifndef LISTTEST_H
#define LISTTEST_H
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "listArray.h"
#include "listPointer.h"

class ListTest : public QObject
{
    Q_OBJECT

 public:

   explicit ListTest(QObject *parent = 0)
        : QObject(parent) {}

private slots:
       void init()
       {
           pList = new ListPointer;
           aList = new ArrayList;
       }

       void testAddPointerList()
       {
           pList->addValueInPos(22,1);
           pList->addValueInPos(23,10);
       }

       void testIsContainedPointerList()
       {
           pList->addValueInPos(22,1);
           pList->addValueInPos(23,10);
           QVERIFY(pList->isContained(22));
           QVERIFY(pList->isContained(23));
           QVERIFY(!(pList->isContained(21)));
       }

       void testRmvPointerList()
       {
           pList->addValueInPos(22,1);
           pList->addValueInPos(23,10);
           pList->removeValue(22);
           QVERIFY(!(pList->isContained(22)));
       }

       void testIsEmptyPointerList()
       {
           QVERIFY(pList->isEmpty());
           pList->addValueInPos(22,1);
           QVERIFY(!(pList->isEmpty()));
       }

       void testLengthPointerList()
       {
           QVERIFY(pList->length() == 0);
           pList->addValueInPos(22,1);
           QVERIFY(pList->length() == 1);
       }

       void testAddArrayList()
       {
           aList->addValueInPos(22,1);
           aList->addValueInPos(23,10);
       }

       void testIsContainedArrayList()
       {
           aList->addValueInPos(22,1);
           aList->addValueInPos(23,10);
           QVERIFY(aList->isContained(22));
           QVERIFY(aList->isContained(23));
           QVERIFY(!(aList->isContained(21)));
       }

       void testRmvArrayList()
       {
           aList->addValueInPos(22,1);
           aList->addValueInPos(23,10);
           aList->removeValue(22);
           QVERIFY(!(aList->isContained(22)));
       }

       void testIsEmptyArrayList()
       {
           QVERIFY(aList->isEmpty());
           aList->addValueInPos(22,1);
           QVERIFY(!(aList->isEmpty()));
       }

       void testLengthArrayList()
       {
           QVERIFY(aList->length() == 0);
           aList->addValueInPos(22,1);
           QVERIFY(aList->length() == 1);
       }


       void cleanup()
       {
           delete pList;
           delete aList;
       }

private:
       ListPointer* pList;
       ArrayList* aList;
   };
#endif // LISTTEST_H
