#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
    int size;
    int rear; // Index of the last element inserted
    T *array;

public:
    Queue(); // Size 100 as default;
    Queue(int size);
    ~Queue();
    int isEmpty();
    void debug();
    void enqueue(T element); // Add element
    T dequeue();             // Remove element
};

#endif