#include <iostream>

#include "consoleOutput.h"
#include "fileOutput.h"

using namespace std;

int main() {
    cout << "Enter the matrix size (odd) ";
    int size;
    cin >> size;
    int counter = 11;
    int **userMatrix = new int*[size + 1];
    for (int i = 0; i < size + 1; i++)
        userMatrix[i] = new int[size + 1];
    cout << "Original matrix: " << endl;
    for (int i = 1; i < size + 1; i++) {
        for (int j = 1; j < size + 1; j++) {
            userMatrix[i][j] = counter;
            counter++;
            cout << userMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Console output:" << endl;
    SpiralOutput* consoleObject = new ConsoleOutput(userMatrix, size);
    consoleObject->print();
    cout << "File output ('output.txt')" << endl;
    SpiralOutput* fileObject = new FileOutput(userMatrix, size);
    fileObject->print();
    for (int i = 1; i <= size; i++)
        delete[] userMatrix[i];
    delete[] userMatrix;
    delete consoleObject;
    delete fileObject;
    return 0;
}

