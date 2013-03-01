#pragma once

class Stack
{
public:
    virtual void push(char value) = 0;
    virtual void pop() = 0;
    virtual bool isEmpty() = 0;
    virtual char top() = 0;
};
