#include "Queue.h"
#include <iostream>

using namespace std;

template <class T>
Queue<T>::Queue()
{
    rear = -1;
    size = 100;
    array = new T[size];
}

template <class T>
Queue<T>::Queue(int size)
{
    rear = -1;
    this->size = size;
    array = new T[size];
}

template <class T>
Queue<T>::~Queue()
{
    delete[] array;
}

template <class T>
int Queue<T>::isEmpty()
{
    if (rear < 0)
    {
        return 1;
    }
    return 0;
}

template <class T>
void Queue<T>::debug()
{
    cout << "Elements in the queue:";
    for (int i = 0; i <= rear; i++)
    {
        cout << " " << array[i];
    }
    cout << endl;
}

template <class T>
void Queue<T>::enqueue(T element)
{
    if (rear >= size - 1)
    {
        throw runtime_error("Can't enqueue when the queue is full.");
    }

    rear++;
    array[rear] = element;
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw runtime_error("Can't dequeue when the queue is empty.");
    }

    T elementDequeued = array[0];

    for (int i = 0; i < rear; i++)
    {
        array[i] = array[i + 1];
    }
    // Shifting all elements like this is not optimal.
    // I think the best solution would probably be to use some form of circular data structure.
    // For simplicity sake, that's fine, though.

    rear--;
    return elementDequeued;
}

template class Queue<int>;
template class Queue<char>;
template class Queue<short>;
template class Queue<long>;
template class Queue<long long>;
template class Queue<unsigned int>;
template class Queue<unsigned char>;
template class Queue<unsigned short>;
template class Queue<unsigned long>;
template class Queue<unsigned long long>;
template class Queue<float>;
template class Queue<double>;
template class Queue<long double>;
template class Queue<bool>;
template class Queue<string>;