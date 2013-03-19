#pragma once
#include <QString>

/**
* @file widget.h
*
* @section DESCRIPTION
*
* Calculator class realization.
*/

class Calculator {
public:
    Calculator();
    void clear();
    void changeExpresion(QString expr);
    void calculate();
    QString expression;
private:
    bool isHaveDot;
    bool needToChangeNumb;
    QString rightNumb;
    QString leftNumb;
    QString currentOpr;
};
