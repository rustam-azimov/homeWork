#pragma once

#include "sorter.h"

/**
 * @file bubbleSort.h
 *
 * @section DESCRIPTION
 *
 * Realization of bubble sort class.
 */

/// BubbleSort class
class BubbleSort : public Sorter {
public:
    /// Calling the base class constructor.
    BubbleSort(int *inputArray, int size) : Sorter(inputArray, size) {}
    /// This is bubble sort realization of base class's abstract mathod.
    void sort();
};

