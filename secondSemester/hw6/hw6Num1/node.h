#ifndef NODE_H
#define NODE_H

/**
  * @file node.h
  *
  * Abstract class Node.
  */

class Node
{
public:
    /// Returns the result of expression.
    virtual int calculate() = 0;

    virtual void print(std::ostream &out) = 0;
    virtual ~Node() {}
};

#endif // NODE_H
