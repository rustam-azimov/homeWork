#pragma once

#include "list.h"

class ArrayList: public List {
public:
    ArrayList();
    void addValueInPos(int value, int position);
    void removeValue(int value);
    bool isEmpty();
    bool isContained(int value);
    int length();
    void print();
    ~ArrayList();
protected:
    int arraySize;
    int arrayCounter;
    int **arrayList;
    int findHole();
    void increaseArray();
};
