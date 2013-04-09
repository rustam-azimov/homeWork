#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "binaryTree.h"

class BalancedTree: public BinaryTree
{
public:
    BalancedTree():
        BinaryTree()
    {}
    void add(T value);
    void remove(T value);
private:
    void balance();
};

#endif // BALANCEDTREE_H
