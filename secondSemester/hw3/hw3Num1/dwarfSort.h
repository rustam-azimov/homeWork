#pragma once

#include "sorter.h"

/**
 * @file dwarfSort.h
 *
 * @section DESCRIPTION
 *
 * Realization of dwarf sort class.
 */

/// DwarfSort class.
class DwarfSort : public Sorter {
public:
    /// Calling the base class constructor.
    DwarfSort(int *inputArray, int size) : Sorter(inputArray, size) {}
    /// This is dwarf sort realization of base class's abstract mathod.
    void sort();
};
