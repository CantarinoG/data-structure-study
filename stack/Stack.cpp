#include "Stack.h"
#include <iostream>

using namespace std;

template <class T>
Stack<T>::Stack()
{
    size = 100;
    top = -1;
    array = new T[size];
}

template <class T>
Stack<T>::Stack(int size)
{
    this->size = size;
    top = -1;
    array = new T[size];
}

template <class T>
Stack<T>::~Stack()
{
    delete[] array;
}

template <class T>
int Stack<T>::isEmpty()
{
    if (top < 0)
    {
        return 1;
    }
    return 0;
}

template <class T>
T Stack<T>::peek()
{
    if (isEmpty())
    {
        throw runtime_error("Can't peek on an empty stack.");
    }
    // todo: test later
    return array[top];
}

template <class T>
void Stack<T>::push(T element)
{
    if (top >= size - 1)
    {
        throw runtime_error("Can't push to a full stack.");
    }
    top++;
    array[top] = element;
}

template <class T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw runtime_error("Can't pop with an empty stack.");
    }

    T elementPopped = peek();
    top--;
    return elementPopped;
}

template <class T>
void Stack<T>::debug()
{
    cout << "Elements in the stack:";
    for (int i = 0; i <= top; i++)
    {
        cout << " " << array[i];
    }
    cout << endl;
}

template class Stack<int>;
template class Stack<char>;
template class Stack<short>;
template class Stack<long>;
template class Stack<long long>;
template class Stack<unsigned int>;
template class Stack<unsigned char>;
template class Stack<unsigned short>;
template class Stack<unsigned long>;
template class Stack<unsigned long long>;
template class Stack<float>;
template class Stack<double>;
template class Stack<long double>;
template class Stack<bool>;
template class Stack<string>;