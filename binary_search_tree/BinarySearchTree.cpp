#include "BinarySearchTree.h"

template <typename T>
BinaryTree<T>::BinaryTree() : root(nullptr) {}

template <typename T>
void BinaryTree<T>::insertNode(T value)
{
    root = insertRecursive(root, value);
}

template <typename T>
Node<T> *BinaryTree<T>::insertRecursive(Node<T> *node, T value)
{
    if (node == nullptr)
        return new Node<T>(value);

    if (value < node->data)
        node->left = insertRecursive(node->left, value);
    else if (value > node->data)
        node->right = insertRecursive(node->right, value);

    return node;
}

template <typename T>
Node<T> *BinaryTree<T>::deleteRecursive(Node<T> *current, T value)
{
    if (current == nullptr)
        return nullptr;

    if (value < current->data)
        current->left = deleteRecursive(current->left, value);
    else if (value > current->data)
        current->right = deleteRecursive(current->right, value);
    else
    {
        // Node to delete found
        // Case 1: Leaf node
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }
        // Case 2: Node with only one child
        else if (current->left == nullptr)
        {
            Node<T> *temp = current->right;
            delete current;
            return temp;
        }
        else if (current->right == nullptr)
        {
            Node<T> *temp = current->left;
            delete current;
            return temp;
        }
        // Case 3: Node with two children
        else
        {
            Node<T> *sucessor = findMin(current->right);
            current->data = sucessor->data;
            current->right = deleteRecursive(current->right, sucessor->data);
        }
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
    if (value < current->data)
        return searchRecursive(current->left, value);
    return searchRecursive(current->right, value);
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
