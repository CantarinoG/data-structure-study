#ifndef ADJACENCYMATRIX_H
#define ADJACENCYMATRIX_H

class AdjacencyMatrix
{
private:
    int vertices; // Number of vertices
    int **adjMatrix;

public:
    AdjacencyMatrix(); // With default number of vertices(10).
    AdjacencyMatrix(int vertices);
    ~AdjacencyMatrix();
    void getEdgeWeight(int src, int dest);
    void addEdge(int src, int dest, int weight);
    void removeEdge(int src, int dest);
    void debug();
};

#endif