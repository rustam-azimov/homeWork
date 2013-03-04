#pragma once

#include "stack.h"


class PointerStack : public Stack {
public:
    PointerStack();
    ~PointerStack();
    void push(double value);
    void pop();
    bool isEmpty() const;
    double top() const;
protected:
    struct Node {
        double value;
        Node* next;
    };
    int nodeCounter;
    Node* head;
};
