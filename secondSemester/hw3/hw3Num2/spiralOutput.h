#pragma once

class SpiralOutput {
public:
    SpiralOutput(int** inputMatrix, int size);
    virtual ~SpiralOutput();
    void goOnSpiral();
    virtual void print() const = 0;
protected:
    int** matrix;
    int matrixSize;
    int* spiralArray;
    int spiralSize;
};
