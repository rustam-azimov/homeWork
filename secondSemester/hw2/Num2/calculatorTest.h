#pragma once
#include <QtCore/QObject>
#include <QtTest/QtTest>

#include "calculator.h"

class CalculatorTest : public QObject
{
    Q_OBJECT

 public:
   explicit CalculatorTest(QObject *parent = 0)
        : QObject(parent) {}

private slots:
       void init()
       {
           calculator = new Calculator((StackType)1, "9523*+8-/");
       }

       void testCalculator()
       {
           QVERIFY(calculator->calculate() == 3);
       }

       void cleanup()
       {
           delete calculator;
       }

private:
       Calculator* calculator;
   };
