#ifndef EXPRESSION_H
#define EXPRESSION_H


#include "node.h"

/**
 * @file expression.h
 *
 * Implementation of class Expression. Expression in form of (<operation sign> <operand1> <operand2>).
 */

class Expression : public Node
{
public:
    Expression(std::istream &in);
    ~Expression();
    /// Returns the result of expression.
    int calculate();
    void print(std::ostream &out);

private:
    char operation;
    Node * left;
    Node * right;

    /** Private method getNode takes Node from stream and decides
     *  whether it is Expression or Number
     */
    Node * getNode(std::istream &in);
};

#endif // EXPRESSION_H

