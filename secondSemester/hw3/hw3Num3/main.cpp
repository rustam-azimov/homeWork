#include "matrixForsort.h"

using namespace std;

int main()
{
    cout << "The program - Sorting matrix:" << endl << endl
         << "Enter the line's size = ";
    int linesSize = 0;
    cin >> linesSize;
    cout << "Enter the colum's size = ";
    int columsSize = 0;
    cin >> columsSize;
    MatrixForSort object = MatrixForSort(linesSize, columsSize);
    cout << endl << "Original matrix:" << endl;
    object.print();
    object.sorting();
    cout << "Sorted matrix:" << endl;
    object.print();
    return 0;
}

