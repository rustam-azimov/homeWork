#pragma once

#include "spiralOutput.h"

 /**
  * @file fileOutput.h
  *
  * @section DESCRIPTION
  *
  * Realization of FileOutput class.
  */

/// FileOutput class.
class FileOutput : public SpiralOutput {
public:
    FileOutput(int** inputMatrix, int size) : SpiralOutput(inputMatrix, size) {}
    /// This method is realization of abstract method in base class.
    /// It print spiralArray in file named 'output.txt'.
    void print() const;
};
