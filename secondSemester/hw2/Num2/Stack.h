#pragma once

enum StackType {
    array = 1,
    pointer = 2
};

class Stack {
public:
    Stack() {}
    virtual void push(double value) = 0;
    virtual void pop() = 0;
    virtual double top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual ~Stack() {}
};
