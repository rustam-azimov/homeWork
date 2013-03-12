#pragma once
#include <cstdlib>
#include <iostream>

class MatrixForSort
{
public:
    MatrixForSort(int size1, int size2);
    ~MatrixForSort();
    void sorting();
    void print();
private:
    int linesSize;
    int columsSize;
    int** array;
    bool needToSwap(int colum1, int colum2);
    void swap(int colum1, int colum2);
};
