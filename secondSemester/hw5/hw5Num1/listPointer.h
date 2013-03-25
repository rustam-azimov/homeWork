#pragma once

#include "list.h"


class PointerList: public List
{
public:
    PointerList();
    void addValueInPos(int value, int position);
    void addFirst(int value);
    void removeValue(int value);
    bool isContained(int value) const;
    bool isEmpty() const;
    int length() const;
    void print() const;
    ~PointerList();
protected:
    struct ListElement
    {
        int value;
        ListElement *next;

        ListElement(ListElement * nextElement, int x = 0) :
            value(x),
            next(nextElement)
        {}
    };
    ListElement *createElement(int value, ListElement *pointer);
    ListElement *list;
    int memberCounter;
};
