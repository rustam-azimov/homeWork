#pragma once

#include "spiralOutput.h"

class FileOutput : public SpiralOutput {
public:
    FileOutput(int** inputMatrix, int size) : SpiralOutput(inputMatrix, size) {}
    void print() const;
};
