#ifndef BAG_H
#define BAG_H

#include <iostream>

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
        tree(NULL)
    {}

    ~Bag()
    {
        remove();
    }

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
    else if (root->multiplicity > 1)
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

template <typename T>
void Bag<T>::remove()
{
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

#endif // BAG_H
