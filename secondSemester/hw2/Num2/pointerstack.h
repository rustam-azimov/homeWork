#pragma once

#include "Stack.h"

struct Node {
    char value;
    Node* next;
};

class PointerStack : public Stack {
public:
    PointerStack();
    ~PointerStack();
    void push(char value);
    void pop();
    bool isEmpty();
    char top();
protected:
    int nodeCounter;
    Node* head;
};
