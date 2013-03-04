#pragma once
#include "arrayStack.h"
#include "pointerStack.h"

enum NumberOrOperator {
    num = 1,
    pls = 2,
    mns = 3,
    mlt = 4,
    dvn = 5
};

class Calculator
{
public:
    Calculator(StackType type, char *ch);
    double calculate();
    ~Calculator();
protected:
    char *expression;
    Stack *stack;
    bool isExpression;
};
