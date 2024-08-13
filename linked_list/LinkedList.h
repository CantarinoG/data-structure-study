#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList();
    void insertAtBeginning(T value);
    void insertAtEnd(T value);
    void insertAtPosition(T value, int position);
    void deleteFromBeginning();
    void deleteFromEnd();
    void deleteFromPosition(int position);
    void debug();
};

#endif