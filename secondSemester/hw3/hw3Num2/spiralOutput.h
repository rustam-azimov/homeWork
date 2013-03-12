#pragma once

 /**
  * @file spiralOutput.h
  *
  * @section DESCRIPTION
  *
  * Realization of interface of output classes.
  */

/// SpiralOutput class - interface.
class SpiralOutput {
public:
    /** Constructor - create matrix with user's size and values.
     * @param inputMatrix - user's matrix.
     * @param size - user's size of the matrix.
     */
    SpiralOutput(int** inputMatrix, int size);
    virtual ~SpiralOutput();
    /// This method go on spiral. Start at the center.
    /// And along the way writes the values ??of elements in the spiralArray.
    void goOnSpiral();
    /// Abstract mathod to print spiralArray.
    virtual void print() const = 0;
protected:
    /// This field holds matrix is ??equivalent to the user's matrix.
    int** matrix;
    /// This field holds size of the class's matrix.
    int matrixSize;
    /// This is array with the elements numbered on spiral.
    int* spiralArray;
    /// This is size of spiralArray (equal number of elemts in matrix).
    int spiralSize;
};
