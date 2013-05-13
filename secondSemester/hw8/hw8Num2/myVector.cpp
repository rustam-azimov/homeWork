#include "myVector.h"

MyVector::MyVector(const int &dimension):
    myDimension(dimension)
{
    vector = new double[myDimension];
    for (int i = 0; i < myDimension; i++)
    {
        vector[i] = 0;
    }
}

MyVector::MyVector(const MyVector &otherVector):
    myDimension(otherVector.myDimension)
{
    vector = new double[myDimension];
    for (int i = 0; i < myDimension; i++)
    {
        vector[i] = otherVector.vector[i];
    }
}

MyVector::~MyVector()
{
    delete[] vector;
}

bool MyVector::isZeroVector()
{
    for (int i = 0; i < myDimension; i++)
    {
        if (vector[i])
        {
            return false;
        }
    }
    return true;
}

void MyVector::setValueAtPosition(const double &value, const int &position) throw (MyVectorException)
{
    if ((position < 0) || (position >= myDimension))
    {
        throw MyVectorException();
    }
    vector[position] = value;
}

double MyVector::valueAtPosition(const int &position) throw (MyVectorException)
{
    if ((position < 0) || (position >= myDimension))
    {
        throw MyVectorException();
    }
    return vector[position];
}

void MyVector::operator +=(const MyVector &otherVector) throw (WrongDimension)
{
    if (myDimension != otherVector.myDimension)
    {
        throw WrongDimension();
    }
    for (int i = 0; i < myDimension; i++)
    {
        vector[i] += otherVector.vector[i];
    }
}

void MyVector::operator -=(const MyVector &otherVector) throw (WrongDimension)
{
    if (myDimension != otherVector.myDimension)
    {
        throw WrongDimension();
    }
    for (int i = 0; i < myDimension; i++)
    {
        vector[i] -= otherVector.vector[i];
    }
}

double MyVector::operator *(const MyVector &otherVector) throw (WrongDimension)
{
    if (myDimension != otherVector.myDimension)
    {
        throw WrongDimension();
    }
    double result = 0;
    for (int i = 0; i < myDimension; i++)
    {
        result += vector[i] * otherVector.vector[i];
    }
    return result;
}
