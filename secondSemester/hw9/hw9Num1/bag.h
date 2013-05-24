#ifndef BAG_H
#define BAG_H

#include <iostream>
#include <QList>

/**
 * @file bag.h
 *
 * Implementation of container class Bag.
 */

template <typename T>
/// @class Bag class-container based on binary tree.
class Bag
{
public:
    Bag():
        tree(NULL),
        count(0)
    {}

    ~Bag()
    {
        remove();
    }

    int elementsCount()
    {
        return count;
    }

    class Iterator;
    bool isEmpty();
    bool isContained(T value);

    void add(T value);
    void removeValue(T value);
    int elementMultiplicity(T value);
    void printInorder();
    /// Removed class content.
    void remove();

protected:
    /// @struct Node containes the implementation of binary tree.
    struct Node
    {
        T value;

        Node *left;
        Node *right;
        int multiplicity;

        Node(Node *leftElement, Node *rightElement, T newValue) :
            value(newValue),
            left(leftElement),
            right(rightElement),
            multiplicity(1)
        {}
    };

    /// Contained binary tree.
    Node *tree;
private:
    int count;
    /// @overload Returned multiplicity of the element in the tree. 0 If isn't contained.
    int elementMultiplicity(Node *&root, T value);

    /// @overload Add value to the tree.
    void add(Node *&root,T value);

    /// @overload Remove value from tree.
    void removeValue(Node *&root, T value);

    /// @overload Returned the smallest of the right values.
    T removeMin(Node *&root);

    /// @overload Print the tree inorder.
    void printInorder(Node *root);

    /// @overload Removed tree.
    void remove(Node *&root);
};

template <typename T>
bool Bag<T>::isEmpty()
{
    return (tree == NULL);
}

template <typename T>
void Bag<T>::add(T value)
{
    count++;
    add(tree, value);
}

template <typename T>
void Bag<T>::add(Node *&root, T value)
{
    if (root == NULL)
    {
        root = new Node(NULL, NULL, value);
        return;
    }
    if (value == root->value)
    {
        root->multiplicity++;
        return;
    }
    if (value < root->value)
        add(root->left, value);
    else
        add(root->right, value);
}

template <typename T>
void Bag<T>::removeValue(T value)
{
    removeValue(tree, value);
}

template <typename T>
void Bag<T>::removeValue(Node *&root, T value)
{
    if (root == NULL)
        return;
    if (value < root->value)
        removeValue(root->left, value);
    else if (value > root->value)
        removeValue(root->right, value);
    else
    {
        count--;
        if (root->multiplicity > 1)
            root->multiplicity--;
        else if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else
            root->value = removeMin(root->right);
    }
}

template <typename T>
T Bag<T>::removeMin(Node *&root)
{
    if (root->left == NULL)
    {
        T result = root->value;
        Node *temp = root;
        root = root->right;
        delete temp;
        temp = NULL;
        return result;
   }
   else
       return removeMin(root->left);
}

template <typename T>
void Bag<T>::remove()
{
    count = 0;
    remove(tree);
}

template<typename T>
void Bag<T>::remove(Node *&root)
{
    while (root != NULL)
    {
        remove(root->left);
        remove(root->right);
        delete root;
        root = NULL;
    }
}

template <typename T>
void Bag<T>::printInorder()
{
    printInorder(tree);
    std::cout << std::endl;
}

template <typename T>
void Bag<T>::printInorder(Bag::Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    for (int i = 0; i < root->multiplicity; i++)
        std::cout << root->value << " ";
    printInorder(root->right);
}

template <typename T>
int Bag<T>::elementMultiplicity(T value)
{
    return elementMultiplicity(tree, value);
}

template <typename T>
int Bag<T>::elementMultiplicity(Node *&root, T value)
{
    if (root == NULL)
        return 0;
    if (root->value == value)
        return root->multiplicity;
    if (root->value > value)
        return elementMultiplicity(root->left, value);
    else
        return elementMultiplicity(root->right, value);
}


template <typename T>
bool Bag<T>::isContained(T value)
{
    return (elementMultiplicity(value) > 0);
}

/// @class Iterator for traversal the class Bag.
template <typename T>
class Bag<T>::Iterator
{
public:
    Iterator(Bag<T> *tree):
        bagTree(tree),
        passedElements(0),
        passedCurElements(0)
    {
        paveTheWay(bagTree->tree);
        if (!way.isEmpty())
            currentElement = way.first();
    }

    bool hasNext()
    {
        if (way.isEmpty())
            return false;
        return (currentElement != way.last());
    }

    /** Return value of currentElement and set him to the next element.
     * If currentElement is the last, method send message,
     * return currentElement's value and don't change currentElement.
     */
    T next()
    {
        if (!hasNext())
        {
            std::cout << "All elements be passed!" << std::endl;
            return currentElement->value;
        }
        passedElements++;
        passedCurElements++;
        if (passedCurElements < currentElement->multiplicity)
        {
            return currentElement->value;
        }
        else
        {
            T result = currentElement->value;
            way.removeFirst();
            currentElement = way.first();
            passedCurElements = 1;
            return result;
        }
    }

    /// Add to the tree new element and rebuild way.
    /// Parameter currentElement has no change.
    void add(T value)
    {
        bagTree->add(value);

        if (value < currentElement->value)
        {
            passedElements++;
        }

        way.clear();
        paveTheWay(bagTree->tree);
        for (int i = 0; i < passedElements; i++)
        {
            way.removeFirst();
        }
        currentElement = way.first();
    }

    /**
      * Remove currentElement from the tree, rebuild way,
      * and set currentElement (if it possible) to the next element.
      * If it isn't posible - set currentElement to the previous element.
      */
    void remove()
    {
        if (!hasNext())
        {
            passedElements--;
        }
        bagTree->removeValue(currentElement->value);
        way.clear();
        paveTheWay(bagTree->tree);
        for (int i = 0; i < passedElements; i++)
        {
            way.removeFirst();
        }
        currentElement = way.first();
    }

private:
    Bag<T>* bagTree;
    QList<Node*> way;
    Node* currentElement;

    /// @param passedElements - counter of traversed elements.
    int passedElements;
    /// @param passedCurrElements - counter of traversed elements with current value.
    int passedCurElements;

    /// This method builds a way from the leftmost to the rightmost child.
    void paveTheWay(Node *root)
    {
        if (root == NULL)
            return;
        paveTheWay(root->left);
        way.append(root);
        paveTheWay(root->right);
    }
};

#endif // BAG_H
