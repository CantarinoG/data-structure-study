#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    T top;
    T *array;

public:
    Stack(); // Creates an stack with size 100 as default.
    Stack(int size);
    int isEmpty();
    T peek();
    void push(T element);
    T pop();
};

#endif