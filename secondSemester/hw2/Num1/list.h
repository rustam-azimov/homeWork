#pragma once

#include <iostream>

using namespace std;


class List {
public:
       List() {};
       virtual void addValueInPos(int value, int position) = 0;
       virtual void removeValue(int value) = 0;
       virtual bool isEmpty() = 0;
       virtual bool isContained(int value) = 0;
       virtual int length() = 0;
       virtual void print() = 0;
       virtual ~List() {};
};
