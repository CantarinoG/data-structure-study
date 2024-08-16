#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include "../linked_list/LinkedList.h"

class AdjacencyList
{
private:
    int vertices; // Number of vertices
    LinkedList<int> *adjList;

public:
    AdjacencyList(int vertices);
    ~AdjacencyList();
    void debug();
    int getEdges(int src);
    int isThereEdge(int src, int dest);
    void addEdge(int src, int dest);
    void removeEdge(int src, int dest);
};

#endif