#include "DynamicArray.h"
#include <iostream>

using namespace std;

template <class T>
DynamicArray<T>::DynamicArray()
{
    capacity = 1;
    size = 0;
    array = new T[capacity];
}

template <class T>
DynamicArray<T>::DynamicArray(int capacity)
{
    this->capacity = capacity; // C++ note: "this" always uses the arrow, not the dot.
    array = new T[capacity];
    size = 0;
}
template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}

template <class T>
int DynamicArray<T>::getSize()
{
    return size;
}

template <class T>
int DynamicArray<T>::getCapacity()
{
    return capacity;
}

template <class T>
void DynamicArray<T>::pushBack(T value)
{
    if (size == capacity)
    { // Array is full, need to extend it.
        growArray();
    }
    array[size] = value;
    size++;
}

template <class T>
void DynamicArray<T>::popBack()
{
    size--;
    if (size == (capacity / 2))
    { // If the current number of element do not go past half of the array
        shrinkArray();
    }
}

template <class T>
void DynamicArray<T>::growArray()
{
    T *newArray = new T[capacity * 2];
    capacity *= 2;

    for (int i = 0; i < size; i++) // Copy each element from the current array into the new array.
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray; // newArray is now the current array.
}

template <class T>
void DynamicArray<T>::shrinkArray()
{
    capacity = size;
    T *newArray = new T[capacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

template <class T>
int DynamicArray<T>::search(T key)
{
    for (int i = 0; i < size; i++)
    { // Go through each element of the array. If that element is equal to key, return it's index.
        if (array[i] == key)
        {
            return i;
        }
    }

    return -1;
}

template <class T>
void DynamicArray<T>::insertAt(int index, T value)
{
    if (size == capacity)
    {
        growArray();
    }

    for (int i = size - 1; i >= index; i--)
    // Goes through the array, starting from last stored element
    // For each element pass it to the next position in the array
    // Stop when "i" is equal to the desired index, who is no able to receive it's new value, since every other value was already passed forward.
    {
        array[i + 1] = array[i];
    }

    array[index] = value;
    size++;
}

template <class T>
void DynamicArray<T>::deleteAt(int index)
{
    for (int i = index; i < size; i++)
    // Goes through the array, starting from the index.
    // For each element, copy the value from the next position.
    // Stop when it gets to the last stored element in the array.
    {
        array[i] = array[i + 1];
    }

    size--;

    if (size == (capacity / 2))
    {
        shrinkArray();
    }
}

template <class T>
bool DynamicArray<T>::isEmpty()
{
    return size == 0;
}

template <class T>
void DynamicArray<T>::debug()
{
    cout << "Elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
    cout << "--------------------------" << endl;
}

// Apparently I must put these for each fucking type this class would be able to handle, otherwise it do not fucking works.
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