#pragma once

#include "list.h"

struct Node {
    int value;
    Node* next;
};

class ListPointer : public List
{
public:
    ListPointer();
    void addValueInPos(int value, int position);
    void removeValue(int value);
    bool isEmpty();
    bool isContained(int value);
    int length();
    void print();
    ~ListPointer();
protected:
    Node* head;
    int nodeCounter;
};
