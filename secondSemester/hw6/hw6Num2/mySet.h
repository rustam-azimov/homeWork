#ifndef MYSET_H
#define MYSET_H

#include <iostream>

/**
 * @file mySet.h
 *
 * Implementation of container class Set.
 */

template <typename T>
/// @class Set class-container based on binary tree.
class Set
{
public:
    Set():
        tree(NULL)
    {}

    /// Copy constructor.
    Set(Set<T> *&set):
        tree(NULL)
    {
        copy(set);
    }

    ~Set()
    {
        remove();
    }

    /// Copied the content of the class.
    void copy(Set<T> *&set);

    bool isEmpty();
    bool isContained(T value);

    void add(T value);
    void removeValue(T value);
    void printInorder();

    /// Returns a set containing the intersection of two sets.
    Set<T> *intersection(Set<T> *&set);

    /// Return a set containing the merge of two sets.
    Set<T> *merge(Set<T> *&set);

    /// Removed class content.
    void remove();

protected:
    /// @struct Node containes the implementation of binary tree.
    struct Node
    {
        T value;

        Node *left;
        Node *right;

        Node(Node *leftElement, Node *rightElement, T newValue) :
            value(newValue),
            left(leftElement),
            right(rightElement)
        {}
    };

    /// Contained binary tree.
    Node *tree;
private:
    /// @overload Copyed Node content.
    void copy(Node *&set);

    /// @overload Returned true, if value contained in the tree. Else returned false.
    bool isContained(Node *&root, T value);

    /// @overload Add value to the tree.
    void add(Node *&root,T value);

    /// @overload Remove value from tree.
    void removeValue(Node *&root, T value);

    /// @overload Returned the smallest of the right values.
    T removeMin(Node *&root);

    /// @overload Print the tree inorder.
    void printInorder(Node *root);

    /// @overload Add same values from tree and set to newSet.
    void intersection(Node *&root, Set<T> *&set, Set<T> *&newSet);

    /// @overload Add all values from tree to newSet.
    void merge(Node *&root, Set<T> *&newSet);

    /// @overload Removed tree.
    void remove(Node *&root);
};

template <typename T>
void Set<T>::copy(Set<T> *&set)
{
    copy(set->tree);
}

template <typename T>
void Set<T>::copy(Node *&root)
{
    if (root != NULL)
    {
        add(tree, root->value);
        copy(root->left);
        copy(root->right);
    }
}

template <typename T>
bool Set<T>::isEmpty()
{
    return (tree == NULL);
}

template <typename T>
void Set<T>::add(T value)
{
    add(tree, value);
}

template <typename T>
void Set<T>::add(Node *&root, T value)
{
    if (root == NULL)
    {
        root = new Node(NULL, NULL, value);
        return;
    }
    if (value == root->value)
        return;
    if (value < root->value)
        add(root->left, value);
    else
        add(root->right, value);
}

template <typename T>
T Set<T>::removeMin(Node *&root)
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
void Set<T>::removeValue(T value)
{
    removeValue(tree, value);
}

template <typename T>
void Set<T>::removeValue(Node *&root, T value)
{
    if (root == NULL)
        return;
    if (value < root->value)
        removeValue(root->left, value);
    else if (value > root->value)
        removeValue(root->right, value);
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
void Set<T>::remove()
{
    remove(tree);
}

template<typename T>
void Set<T>::remove(Node *&root)
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
void Set<T>::printInorder()
{
    printInorder(tree);
    std::cout << std::endl;
}

template <typename T>
void Set<T>::printInorder(Set::Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    std::cout << root->value << " ";
    printInorder(root->right);
}

template <typename T>
bool Set<T>::isContained(T value)
{
    return isContained(tree, value);
}

template <typename T>
bool Set<T>::isContained(Node *&root, T value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value > value)
        return isContained(root->left, value);
    else
        return isContained(root->right, value);
}

template <typename T>
Set<T> *Set<T>::intersection(Set<T> *&set)
{
    Set<T> *newSet = new Set<T>;
    intersection(tree, set, newSet);
    return newSet;
}

template <typename T>
void Set<T>::intersection(Node *&root, Set<T> *&set, Set<T> *&newSet)
{
    if (root != NULL)
    {
        if (set->isContained(root->value))
        {
            newSet->add(root->value);
        }
        intersection(root->left, set, newSet);
        intersection(root->right, set, newSet);
    }
}

template <typename T>
Set<T> *Set<T>::merge(Set<T> *&set)
{
    Set<T> *newSet = new Set<T>(set);
    merge(tree, newSet);
    return newSet;
}

template <typename T>
void Set<T>::merge(Node *&root, Set<T> *&newSet)
{
    if (root != NULL)
    {
        newSet->add(root->value);
        merge(root->left, newSet);
        merge(root->right, newSet);
    }
}

#endif // MYSET_H
