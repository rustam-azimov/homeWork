#pragma once

#include "spiralOutput.h"

class ConsoleOutput : public SpiralOutput {
public:
    ConsoleOutput(int** inputMatrix, int size) : SpiralOutput(inputMatrix, size) {}
    void print() const;
};
