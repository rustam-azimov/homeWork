#pragma once
#include <cstdlib>
#include <iostream>

 /**
  * @file matrixForSort.h
  *
  * @section DESCRIPTION
  *
  * MatrixForSort class realization.
  */

///MatrixForSort class.
class MatrixForSort
{
public:
    /// Constructor - create matrix with user's size.
    /// @param size1 - parameter specifies the number of lines.
    /// @param size2 - parameter specifies the number of columns.
    MatrixForSort(int size1, int size2);
    /// Destructor.
    ~MatrixForSort();
    /** This method sorts the array. This is done by the bubble sort,
     * the need to change two columns places recognized by the method 'needToSwap'
     * and change itself is done through a mathod 'swap'.
     */
    void sorting();
    /// This method displays the console matrix,
    /// separating the elements of one line by spaces, and lines - by newlines.
    void print();
private:
    /// This field holds a number of lines.
    int linesSize;
    /// This field holds a number of columns.
    int columsSize;
    /// This field is two-dimensional array,
    /// whose elements - elements of the original matrix.
    int** array;
    /** This method takes a number of two columns and compares
      * the first column with the second.
      * Returns true if they need to be swapped, false if they dont.
      */
    bool needToSwap(int colum1, int colum2);
    /// This method takes a number of two columns and swap element's value of these columns.
    void swap(int colum1, int colum2);
};
