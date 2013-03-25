#pragma once

 /**
  * @file sorter.h
  *
  * @section DESCRIPTION
  *
  * Realization of interface of sorting classes.
  */

/// Sorter class - interface.
class Sorter {
public:
    /** Constructor - create array with user's size and values.
     * @param inputArray - user's array.
     * @param size - user's size of the array.
     */
    Sorter(int *inputArray, int size);
    /// Abstract sort function.
    virtual void sort() = 0;
    /// This method displays the console matrix,
    /// separating the elements of the array by spaces.
    void print();
    /// Virtual destructor.
    int* returnArray() {
        return array;
    }
    virtual ~Sorter();
 protected:
    /// This field is array, whose elements -
    /// elements of the original array.
    int *array;
    /// This field holds a size of the array.
    int arraySize;
};
