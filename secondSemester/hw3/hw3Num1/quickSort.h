#pragma once

#include "sorter.h"

class QuickSort : public Sorter {
public:
    QuickSort(int* inputArray, int size) : Sorter(inputArray, size) {}
    void sort();
    void qSort(int first, int last);
};
