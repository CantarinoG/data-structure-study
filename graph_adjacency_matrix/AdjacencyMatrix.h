#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

class AdjacencyMatrix
{
private:
    int vertices; // Number of vertices
    int initialValue;
    int **adjMatrix;

public:
    AdjacencyMatrix(int vertices, int initialValue = 0); // vertices is the number of vertices(size) in the graph; initialValue can be specified if 0 is a valid weight in that graph.
    ~AdjacencyMatrix();
    void debug();
    int getEdge(int src, int dest);                  // Return the value in that edge.
    void addEdge(int src, int dest, int weight = 1); // Weight is optional, so if the client code wants to use an undirected graph they don't need to worry about passing a value.
    void removeEdge(int src, int dest);
};

#endif