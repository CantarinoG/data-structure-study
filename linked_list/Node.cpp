#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
Node<T>::Node()
{
    next = NULL;
}

template <class T>
Node<T>::Node(T data, Node *next)
{
    this->data = data;
    this->next = next;
}

template <class T>
Node<T>::~Node()
{
    next = NULL;
}

template class Node<int>;
template class Node<char>;
template class Node<short>;
template class Node<long>;
template class Node<long long>;
template class Node<unsigned int>;
template class Node<unsigned char>;
template class Node<unsigned short>;
template class Node<unsigned long>;
template class Node<unsigned long long>;
template class Node<float>;
template class Node<double>;
template class Node<long double>;
template class Node<bool>;
template class Node<string>;