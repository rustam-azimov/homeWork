#pragma once

#include "stack.h"

class ArrayStack: public Stack {
public:
    ArrayStack();
    void push(double value);
    void pop();
    double top() const;
    bool isEmpty() const;
    ~ArrayStack();
protected:
    double **arrayStack;
    int arrayCounter;
    int arraySize;
    int findHole() const;
    void increaseArray();
};
