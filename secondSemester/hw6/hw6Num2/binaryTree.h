#ifndef BinaryTree_H
#define BinaryTree_H

#include <iostream>

template <typename T>
class BinaryTree
{
public:
    BinaryTree():
        tree(NULL),
        memberCounter(0)
    {}

    ~BinaryTree()
    {
        clearTree();
    }

    bool isEmpty();
    void add(T value);
    void remove(T value);
    bool isContained(T value);
    void printInorder();
    void clearTree();
protected:
    struct Node
    {
        T value;

        Node *left;
        Node *right;

        int height;

        Node(Node *leftElement, Node *rightElement, T newValue) :
            value(newValue),
            left(leftElement),
            right(rightElement)
        {}
    };
    Node *tree;
    int memberCounter;
private:
    void add(Node *&root,T value);
    void remove(Node *&root, T value);
    T removeMin(Node *&root);
    void clearTree(Node *&root);
    bool isContained(Node *&root, T value);
    void printInorder(Node *root);
};

template<typename T>
bool BinaryTree<T>::isEmpty()
{
    return (tree == NULL);
}

template<typename T>
void BinaryTree<T>::add(T value)
{
    add(tree, value);
}

template<typename T>
void BinaryTree<T>::add(Node *&root, T value)
{
    if (root == NULL)
    {
        root = new Node(NULL, NULL, value);
        return;
    }
    if (value < root->value)
        add(root->left, value);
    else
        add(root->right, value);
}

template<typename T>
T BinaryTree<T>::removeMin(Node *&root)
{
    if (root->left == NULL)
    {
        int result = root->value;
        Node *temp = root;
        root = root->right;
        delete temp;
        temp = NULL;
        return result;
   }
   else
       return removeMin(root->left);
}

template<typename T>
void BinaryTree<T>::remove(T value)
{
    remove(tree, value);
}

template<typename T>
void BinaryTree<T>::remove(Node *&root, T value)
{
    if (root == NULL)
        return;
    if (value < root->value)
        remove(root->left, value);
    else if (value > root->value)
        remove(root->right, value);
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

template<typename T>
void BinaryTree<T>::clearTree()
{
    clearTree(tree);
}

template<typename T>
void BinaryTree<T>::clearTree(Node *&root)
{
    while (root != NULL)
    {
        clearTree(root->left);
        clearTree(root->right);
        delete root;
        root = NULL;
    }
}

template<typename T>
void BinaryTree<T>::printInorder()
{
    printInorder(tree);
}

template<typename T>
void BinaryTree<T>::printInorder(BinaryTree::Node *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    std::cout << root->value << " ";
    printInorder(root->right);
}

template<typename T>
bool BinaryTree<T>::isContained(T value)
{
    return isContained(tree, value);
}

template<typename T>
bool BinaryTree<T>::isContained(Node *&root,T value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (root->value < value)
        isContained(root->left, value);
    else
        isContained(root->right, value);
}


#endif // BinaryTree_H
