// A strict binary tree cannot have nodes with only one child, it's either two or none.
// A perfect binary tree will have all levels complete, except for the last one, which will be made all from leaves.
// The maximum number of nodes at level i is 2^i, where i is the number of levels in the tree(the root is level 0).
// The maximum number of nodes in total is (2^(i + 1)) - 1, where is the last level in the three.
#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
void BinaryTree<T>::insertNode(T value)
{
    Node<T> *newNode = new Node<T>(value);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    std::queue<Node<T> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<T> *current = q.front();
        q.pop();

        if (current->left == nullptr)
        {
            current->left = newNode;
            return;
        }
        else
        {
            q.push(current->left);
        }

        if (current->right == nullptr)
        {
            current->right = newNode;
            return;
        }
        else
        {
            q.push(current->right);
        }
    }
}

template <typename T>
Node<T> *BinaryTree<T>::deleteRecursive(Node<T> *current, T value)
{
    if (current == nullptr)
        return nullptr;

    if (current->data == value)
    {
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }
        if (current->left == nullptr)
        {
            Node<T> *temp = current->right;
            delete current;
            return temp;
        }
        if (current->right == nullptr)
        {
            Node<T> *temp = current->left;
            delete current;
            return temp;
        }

        Node<T> *successor = findMin(current->right);
        current->data = successor->data;
        current->right = deleteRecursive(current->right, successor->data);
    }
    else
    {
        current->left = deleteRecursive(current->left, value);
        current->right = deleteRecursive(current->right, value);
    }
    return current;
}

template <typename T>
void BinaryTree<T>::deleteNode(T value)
{
    root = deleteRecursive(root, value);
}

template <typename T>
Node<T> *BinaryTree<T>::findMin(Node<T> *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

template <typename T>
bool BinaryTree<T>::searchRecursive(Node<T> *current, T value)
{
    if (current == nullptr)
        return false;
    if (current->data == value)
        return true;
    return searchRecursive(current->left, value) || searchRecursive(current->right, value);
}

template <typename T>
bool BinaryTree<T>::search(T value) // Made with depth-first search.
{
    return searchRecursive(root, value);
}

template <typename T>
void BinaryTree<T>::inorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        inorderRecursive(node->left);
        std::cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

template <typename T>
void BinaryTree<T>::inorder()
{
    inorderRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::preorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        std::cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }
}

template <typename T>
void BinaryTree<T>::preorder()
{
    preorderRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::postorderRecursive(Node<T> *node)
{
    if (node != nullptr)
    {
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        std::cout << node->data << " ";
    }
}

template <typename T>
void BinaryTree<T>::postorder()
{
    postorderRecursive(root);
    std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::levelorder() // Breadth-first search
{
    if (root == nullptr)
        return;

    std::queue<Node<T> *> q;
    q.push(root);

    while (!q.empty())
    {
        Node<T> *current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    std::cout << std::endl;
}

template class BinaryTree<int>;
template class BinaryTree<char>;
template class BinaryTree<short>;
template class BinaryTree<long>;
template class BinaryTree<long long>;
template class BinaryTree<unsigned int>;
template class BinaryTree<unsigned char>;
template class BinaryTree<unsigned short>;
template class BinaryTree<unsigned long>;
template class BinaryTree<unsigned long long>;
template class BinaryTree<float>;
template class BinaryTree<double>;
template class BinaryTree<long double>;
template class BinaryTree<bool>;
template class BinaryTree<std::string>;
