#pragma once

#include "sorter.h"

class BubbleSort : public Sorter {
public:
    BubbleSort(int *inputArray, int size) : Sorter(inputArray, size) {}
    void sort();
};

