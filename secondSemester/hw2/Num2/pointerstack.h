#pragma once

#include "stack.h"


class PointerStack : public Stack {
public:
    PointerStack();
    ~PointerStack();
    void push(char value);
    void pop();
    bool isEmpty();
    char top();
protected:
    struct Node {
        char value;
        Node* next;
    };
    int nodeCounter;
    Node* head;
};
