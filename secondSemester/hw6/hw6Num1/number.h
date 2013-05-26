#ifndef NUMBER_H
#define NUMBER_H

#include "node.h"

/**
  * @file number.h
  *
  * Implementation of class Number.
  */

class Number : public Node
{
public:
    Number(std::istream &in) { in >> value; }
    int calculate() { return value; }
    void print(std::ostream &out) { out << value; }

private:
    int value;
};

#endif // NUMBER_H
