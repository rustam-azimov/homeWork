#ifndef MYVECTOR_H
#define MYVECTOR_H

class MyVectorException {};
class WrongDimension : public MyVectorException
{};

/// @class MyVector for use with R^n vectors.
class MyVector
{
public:
    /// Constructor with indicating dimension.
    MyVector(const int& dimension);
    /// Copy constructor.
    MyVector(const MyVector* otherVector);
    ~MyVector();
    /// Return true if all of values in array vector are equal to zero.
    /// Otherwise return false.
    bool isZeroVector();
    /// @throw MyVectorException If an invalid position.
    void setValueAtPosition(const double& value, const int& position) throw (MyVectorException);
    double valueAtPosition(const int& position) throw (MyVectorException);
    /// Changes will be left vector.
    /// @throw WrongDimension If the dimensions of the vectors do not identical.
    void operator += (const MyVector& otherVector) throw (WrongDimension);
    void operator -= (const MyVector& otherVector) throw (WrongDimension);
    /// Scalar multiplication.
    double operator * (const MyVector& otherVector) throw (WrongDimension);

private:
    const int myDimension;
    double* vector;
};

#endif // MYVECTOR_H
