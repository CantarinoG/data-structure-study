#include "DynamicArray.h"
#include <iostream>

using namespace std;

DynamicArray::DynamicArray()
{
    capacity = 1;
    size = 0;
    array = new int[capacity];
}

DynamicArray::DynamicArray(int capacity)
{
    this->capacity = capacity; // C++ note: "this" always uses the arrow, not the dot.
    array = new int[capacity];
    size = 0;
}

int DynamicArray::getSize()
{
    return size;
}

int DynamicArray::getCapacity()
{
    return capacity;
}

void DynamicArray::pushBack(int value)
{
    if (size == capacity)
    { // Array is full, need to extend it.
        growArray();
    }
    array[size] = value;
    size++;
}

void DynamicArray::popBack()
{
    array[size - 1] = 0;
    size--;
    if (size == (capacity / 2))
    { // If the current number of element do not go past half of the array
        shrinkArray();
    }
}

void DynamicArray::growArray()
{
    int *newArray = new int[capacity * 2];
    capacity *= 2;

    for (int i = 0; i < size; i++) // Copy each element from the current array into the new array.
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray; // newArray is now the current array.
}

void DynamicArray::shrinkArray()
{
    capacity = size;
    int *newArray = new int[capacity];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

int DynamicArray::search(int key)
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

void DynamicArray::insertAt(int index, int value)
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

void DynamicArray::deleteAt(int index)
{
    for (int i = index; i < size; i++)
    // Goes through the array, starting from the index.
    // For each element, copy the value from the next position.
    // Stop when it gets to the last stored element in the array.
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = 0; // Removes the last stored element(that is now stored one position behind).

    size--;

    if (size == (capacity / 2))
    {
        shrinkArray();
    }
}

bool DynamicArray::isEmpty()
{
    return size == 0;
}

void DynamicArray::debug()
{
    cout << "Elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Size: " << size << endl;
    cout << "Capacity: " << capacity << endl;
}