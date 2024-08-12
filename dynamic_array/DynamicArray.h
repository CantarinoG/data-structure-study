#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray
{
private:
    int *array;   // The array
    int size;     // The number of elements I have
    int capacity; // The number of element in the array

public:
    DynamicArray();             // Default constructor(will have size 1)
    DynamicArray(int capacity); // Constructor receiving size as argument

    ~DynamicArray();

    int getSize();

    int getCapacity();

    void pushBack(int value); // Insert elements after last stored index

    void popBack(); // Delete element at last stored index

    void growArray(); // Substitute the current array for one of double the size

    void shrinkArray(); // Substitute the current array for one of half the size

    int search(int key); // Search for element in the array

    void insertAt(int index, int value); // Insert element at given index

    void deleteAt(int index); // Delete element at given index

    void debug(); // Print array details for debugging purposes
};

#endif