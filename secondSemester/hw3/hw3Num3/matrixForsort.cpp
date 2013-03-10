#include "matrixForsort.h"

using namespace std;

MatrixForSort::MatrixForSort(int size1, int size2) {
    linesSize = size1;
    columsSize = size2;
    array = new int*[linesSize];
    for(int i = 0; i < linesSize; i++)
        array[i] = new int[columsSize];
    for(int i = 0; i < linesSize; i++)
        for(int k = 0; k < columsSize; k++)
            array[i][k] = rand() % 10;
}

bool MatrixForSort::needToSwap(int colum1, int colum2) {
    for (int i = 0; i < linesSize; i++)
        if (array[i][colum1] != array[i][colum2]) {
            if (array[i][colum1] > array[i][colum2])
                return true;
            else
                return false;
        }
    return false;
}

void MatrixForSort::swap(int colum1, int colum2) {
    int tempValue;
    for (int i = 0; i < linesSize; i++) {
        tempValue = array[i][colum1];
        array[i][colum1] = array[i][colum2];
        array[i][colum2] = tempValue;
    }
}

void MatrixForSort::sorting() {
    for (int k = 0; k < columsSize - 1; k++)
        for (int i = 0; i < columsSize - k - 1; i++)
            if (needToSwap(i, i + 1))
                swap(i, i + 1);
}

void MatrixForSort::print() {
    for (int i = 0; i < linesSize; i++) {
        for (int k = 0; k < columsSize; k++)
            cout << array[i][k] << " ";
        cout << endl;
    }
}
MatrixForSort::~MatrixForSort() {
    for (int i = 0; i < linesSize; i++)
        delete[] array[i];
    delete[] array;
}
