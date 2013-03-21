#pragma once

#include <QtCore/QObject>
#include <QtTest/QtTest>
#include "calculator.h"

class CalculatorTest : public QObject {
    Q_OBJECT
public:
    explicit CalculatorTest(QObject*parent = 0)
        : QObject(parent) {}

private slots:
    void init() {
        calculator = new Calculator;
    }

    void cleanup() {
        delete calculator;
    }

    void testChangeExpresion() {
        calculator->changeExpresion("2");
        QVERIFY(calculator->expression == "2");
        calculator->changeExpresion("+");
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        QVERIFY(calculator->expression == "34");
    }
    void testClearAndChange() {
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        QVERIFY(calculator->expression == "34");
        calculator->clear();
        QVERIFY(calculator->expression == "");
    }

    void testCalculateAndChange() {
        calculator->changeExpresion("2");
        calculator->changeExpresion("*");
        calculator->changeExpresion("3");
        calculator->changeExpresion("4");
        calculator->calculate();
        QVERIFY(calculator->expression == "68");
    }

private:
    Calculator* calculator;
};

QTEST_MAIN(CalculatorTest)
