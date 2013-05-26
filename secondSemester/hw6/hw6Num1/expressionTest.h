#ifndef EXPRESSIONTEST_H
#define EXPRESSIONTEST_H

#include <QtTest/QtTest>
#include <sstream>
#include <string>
#include "expression.h"

class ExpressionTest : public QObject
{
    Q_OBJECT
private slots:
    void testSimpleExpression()
    {
        std::string expr("(* (+ 1 1) 2)");
        std::stringstream in("(* (+ 1 1) 2)");
        std::stringstream out;

        Expression expression(in);
        expression.print(out);

        QVERIFY(out.str() == expr);
        QVERIFY(expression.calculate() == 4);
    }

    void testComplexExpression()
    {
        std::string expr("(+ (* (- 5 6) 7) (/ (+ 1 2) 3))");
        std::stringstream in("(+ (* (- 5 6) 7) (/ (+ 1 2) 3))");
        std::stringstream out;
        Expression expression(in);
        expression.print(out);
        QVERIFY(out.str() == expr);
        QVERIFY(expression.calculate() == -6);
    }
};

#endif // EXPRESSIONTEST_H


