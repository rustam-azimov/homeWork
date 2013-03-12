#pragma once

#include "spiralOutput.h"

 /**
  * @file consoleOutput.h
  *
  * @section DESCRIPTION
  *
  * Realization of ConsoleOutput class.
  */


class ConsoleOutput : public SpiralOutput {
public:
    ConsoleOutput(int** inputMatrix, int size) : SpiralOutput(inputMatrix, size) {}
    /// This method is realization of abstract method in base class.
    /// It output spiralArray on the console, separating elements by spaces.
    void print() const;
};
