#include "Node.h"
using namespace std;

template <class T>
Node<T>::Node()
{
    data = NULL;
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

template class DynamicArray<int>;
template class DynamicArray<char>;
template class DynamicArray<short>;
template class DynamicArray<long>;
template class DynamicArray<long long>;
template class DynamicArray<unsigned int>;
template class DynamicArray<unsigned char>;
template class DynamicArray<unsigned short>;
template class DynamicArray<unsigned long>;
template class DynamicArray<unsigned long long>;
template class DynamicArray<float>;
template class DynamicArray<double>;
template class DynamicArray<long double>;
template class DynamicArray<bool>;
template class DynamicArray<string>;