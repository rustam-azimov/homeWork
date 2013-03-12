#pragma once

#include "sorter.h"

/**
 * @file quickSort.h
 *
 * @section DESCRIPTION
 *
 * Realization of quick sort class.
 */

/// QuickSort class.
class QuickSort : public Sorter {
public:
    /// Calling the base class constructor.
    QuickSort(int* inputArray, int size) : Sorter(inputArray, size) {}
    /// This is dwarf sort realization of base class's abstract mathod.
    /// Calling the method qSort.
    void sort();
    /**
     * This method takes left and right limits and sorting by quick sort.
     * @param first - holds number of left limit.
     * @param last - holds number of right limit.
    void qSort(int first, int last);
};
