// Code adapted from geeksforgeeks
#ifndef NODE_H
#define NODE_H

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node();
    Node(T data, Node *next);
    ~Node();
};

#endif