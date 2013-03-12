#include "spiralOutput.h"

SpiralOutput::SpiralOutput(int **inputMatrix, int size) {
    matrixSize = size;
    matrix = new int*[matrixSize + 1];
    for (int i = 0; i <= matrixSize; i++)
        matrix[i] = new int[matrixSize + 1];
    for (int i = 1; i <= matrixSize; i++)
        for (int j = 1; j <= matrixSize; j++)
            matrix[i][j] = inputMatrix[i][j];
    spiralSize = matrixSize * matrixSize;
    spiralArray = new int[spiralSize];
    for (int i = 0; i < spiralSize; i++)
        spiralArray[i] = 0;
    goOnSpiral();
}

SpiralOutput::~SpiralOutput() {
    for (int i = 0; i <= matrixSize; i++)
        delete[] matrix[i];
    delete[] matrix;
    delete[] spiralArray;
}

void SpiralOutput::goOnSpiral() {
    int line = int(matrixSize / 2) + 1;
    int column = int(matrixSize / 2) + 1;
    int spiralCounter = 0;
    spiralArray[spiralCounter] = matrix[line][column];
    spiralCounter++;
    for (int i = 1; i <= matrixSize; i++) {
        if ((i % 2) != 0) {
            for (int j = 1; j <= i && !((line == matrixSize) && (column == matrixSize)); j++) {
                column++;
                spiralArray[spiralCounter] = matrix[line][column];
                spiralCounter++;
            }
            for (int j = 1; j <= i && !((line == matrixSize) && (column == matrixSize)); j++) {
                line--;
                spiralArray[spiralCounter] = matrix[line][column];
                spiralCounter++;
            }
        }
        if ((i % 2) == 0) {
            for (int j = 1; j <= i && !((line == matrixSize) && (column == matrixSize)); j++) {
                column--;
                spiralArray[spiralCounter] = matrix[line][column];
                spiralCounter++;
            }
            for (int j = 1; j <= i && !((line == matrixSize) && (column == matrixSize)); j++) {
                line++;
                spiralArray[spiralCounter] = matrix[line][column];
                spiralCounter++;
            }
        }
    }
}
