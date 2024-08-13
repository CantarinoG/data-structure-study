#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
private:
    Node *head;

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