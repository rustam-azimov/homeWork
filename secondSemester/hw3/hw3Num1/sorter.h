#pragma once

class Sorter {
public:
    Sorter(int *inputArray, int size);
    virtual void sort() = 0;
    void print();
    virtual ~Sorter();
 protected:
    int *array;
    int arraySize;
};
