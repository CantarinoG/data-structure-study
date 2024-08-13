#include "LinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
}

template <class T>
void LinkedList<T>::insertAtBeginning(T value)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = value;
    newNode->next = head; // Points to the node that was in head.
    head = newNode;       // Head attribute now points to this node.
}

template <class T>
void LinkedList<T>::insertAtEnd(T value)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = value;
    newNode->next = NULL;

    if (!head)
    { // If the list is empty, this node will be at the head.
        head = newNode;
        return;
    }

    Node<T> *tempNode = head;
    while (tempNode->next) // Goes until there is no next node(last element)
    {
        tempNode = tempNode->next;
    }

    tempNode->next = newNode; // The last node's next will be the newly created node
}

template <class T>
void LinkedList<T>::insertAtPosition(T value, int position)
{
    if (position < 1)
    {
        throw runtime_error("Position should be >= 1.");
    }

    if (position == 1)
    {
        insertAtBeginning(value);
        return;
    }

    Node<T> *newNode = new Node<T>();
    newNode->data = value;

    Node<T> *tempNode = head;
    for (int i = 1; i < position - 1 && tempNode; ++i)
    {
        tempNode = tempNode->next;
    } // tempNode goes through the list until it contains the node in the position

    if (!tempNode)
    {
        throw runtime_error("Position out of range.");
    }

    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

template <class T>
void LinkedList<T>::deleteFromBeginning()
{
    if (!head)
    {
        throw runtime_error("List is empty.");
    }

    // Node tempNode = head;
    head = head->next;
    // delete tempNode;
}

template <class T>
void LinkedList<T>::deleteFromEnd()
{
    if (!head)
    {
        throw runtime_error("List is empty.");
    }

    if (!head->next)
    {
        head = NULL;
        return;
    }

    // Goes to the second to last node
    Node<T> *tempNode = head;
    while (tempNode->next->next)
    {
        tempNode = tempNode->next;
    }

    tempNode->next = NULL;
}

template <class T>
void LinkedList<T>::deleteFromPosition(int position)
{
    if (position < 1)
    {
        throw runtime_error("Position should be >= 1.");
    }

    if (position == 1)
    {
        deleteFromBeginning();
        return;
    }

    Node<T> *tempNode = head;
    for (int i = 1; i < position - 1 && tempNode; ++i)
    {
        // Goes through the array until it finds the node in the position
        tempNode = tempNode->next;
    }

    if (!tempNode || tempNode->next == NULL)
    {
        throw runtime_error("Position out of range.");
    }

    Node<T> *toDelete = tempNode->next;
    tempNode->next = tempNode->next->next;
    delete toDelete;
}

template <class T>
void LinkedList<T>::debug()
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node<T> *tempNode = head;
    while (tempNode != NULL)
    {
        cout << tempNode->data << " -> ";
        tempNode = tempNode->next;
    }
    cout << "NULL" << endl;
}

template class LinkedList<int>;
template class LinkedList<char>;
template class LinkedList<short>;
template class LinkedList<long>;
template class LinkedList<long long>;
template class LinkedList<unsigned int>;
template class LinkedList<unsigned char>;
template class LinkedList<unsigned short>;
template class LinkedList<unsigned long>;
template class LinkedList<unsigned long long>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<long double>;
template class LinkedList<bool>;
template class LinkedList<string>;