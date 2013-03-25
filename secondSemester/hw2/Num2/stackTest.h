#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "pointerStack.h"
#include "arrayStack.h"

class StackTest : public QObject
{
    Q_OBJECT

 public:

   explicit StackTest(QObject *parent = 0)
        : QObject(parent) {}

private slots:
       void init()
       {
           pStack = new PointerStack;
           aStack = new ArrayStack;
       }

       void testPushPStack()
       {
           pStack->push(22.1);
           pStack->push(11);
       }

       void testTopPStack()
       {
           pStack->push(22.1);
           QVERIFY(pStack->top() == 22.1);
           pStack->push(11);
           QVERIFY(pStack->top() == 11);
       }

       void testPopPStack()
       {
           pStack->push(22.1);
           pStack->push(11);
           pStack->pop();
           QVERIFY(pStack->top() == 22.1);
       }

       void testIsEmptyPStack()
       {
           QVERIFY(pStack->isEmpty());
           pStack->push(221);
           QVERIFY(!(pStack->isEmpty()));
       }

       void testPushAStack()
       {
           aStack->push(22.1);
           aStack->push(11);
       }

       void testTopAStack()
       {
           aStack->push(22.1);
           QVERIFY(aStack->top() == 22.1);
           aStack->push(11);
           QVERIFY(aStack->top() == 11);
       }

       void testPopAStack()
       {
           aStack->push(22.1);
           aStack->push(11);
           aStack->pop();
           QVERIFY(aStack->top() == 22.1);
       }

       void testIsEmptyAStack()
       {
           QVERIFY(aStack->isEmpty());
           aStack->push(221);
           QVERIFY(!(aStack->isEmpty()));
       }

       void cleanup()
       {
           delete pStack;
           delete aStack;
       }

private:
       PointerStack* pStack;
       ArrayStack* aStack;
   };
