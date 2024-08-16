#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H
#include <vector>

class AdjacencyList
{
private:
    int vertices; // Number of vertices
    std::vector<int> *adjList;

public:
    AdjacencyList(int vertices);
    ~AdjacencyList();
    void debug();
    void handleUnallowedValue(int value);
    std::vector<int> getEdges(int src);
    int isThereEdge(int src, int dest);
    void addEdge(int src, int dest);
    int getVectorIndex(int src, int dest);
    void removeEdge(int src, int dest);
};

#endif