#include <iostream>
#include <fstream>
#include <cctype>
#include "expression.h"
#include "number.h"

const int operNum = 4;
const char operations[] = {'+', '-', '*', '/'};

int Expression::calculate()
{
    switch (operation)
    {
        case '+' :
            return left->calculate() + right->calculate(); 
        case '-' :
            return left->calculate() - right->calculate(); 
        case '*' :
            return left->calculate() * right->calculate(); 
        default:
            return left->calculate() / right->calculate(); 
    }
}

void Expression::print(std::ostream &out)
{
    out << '(' << operation << ' ';
    left->print(out);
    out << ' ';
    right->print(out);
    out << ')';
}

Node * Expression::getNode(std::istream &in)
{
    while (isspace(in.peek()))
        in.get();
    
    if (in.peek() == '(')
        return new Expression(in);
    
    if (in.peek() >= '0' && in.peek() <= '9')
        return new Number(in); 

}

Expression::Expression(std::istream &in)
{
    in.get();
    in >> operation;

    while (isspace(operation))
        in >> operation;

    left = getNode(in);
    right = getNode(in);

    in.get();
}

Expression::~Expression()
{
    delete left;
    delete right;
}


