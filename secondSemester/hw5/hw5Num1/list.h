#pragma once

#include <iostream>

using namespace std;

class List
{
public:
    virtual void addValueInPos(int value, int position) = 0;
    virtual void addFirst(int value) = 0;
    virtual void removeValue(int value) = 0;
    virtual bool isContained(int value) const = 0;
    virtual bool isEmpty() const = 0;
    virtual int length() const = 0;
    virtual void print() const = 0;
    virtual ~List() {};
};
