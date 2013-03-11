#pragma once

#include "sorter.h"

class DwarfSort : public Sorter {
public:
    DwarfSort(int *inputArray, int size) : Sorter(inputArray, size) {}
    void sort();
};
