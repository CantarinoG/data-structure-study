#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "./Node.h"
#include <iostream>
#include <queue>

template <typename T>
class BinaryTree
{
private:
    Node<T> *root;
    Node<T> *deleteRecursive(Node<T> *current, T value);
    Node<T> *findMin(Node<T> *node);
    bool searchRecursive(Node<T> *current, T value);
    void inorderRecursive(Node<T> *node);
    void preorderRecursive(Node<T> *node);
    void postorderRecursive(Node<T> *node);

public:
    BinaryTree();
    void insertNode(T value);
    void deleteNode(T value);
    bool search(T value);
    void inorder();
    void preorder();
    void postorder();
    void levelorder();
};

#endif