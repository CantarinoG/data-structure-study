#include "AdjacencyMatrix.h"
#include <iostream>

using namespace std;

AdjacencyMatrix::AdjacencyMatrix(int vertices, int initialValue)
{
    this->vertices = vertices;
    this->initialValue = initialValue;
    adjMatrix = new int *[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjMatrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = initialValue;
        }
    }
}

AdjacencyMatrix::~AdjacencyMatrix()
{
    for (int i = 0; i < vertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;
}

void AdjacencyMatrix::debug()
{
    cout << "=======================" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << " " << i << "\t";
    }
    cout << endl;
    cout << "-------------------------" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << i << "| ";
        for (int j = 0; j < vertices; j++)
        {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "=======================" << endl;
}

int AdjacencyMatrix::getEdge(int src, int dest)
{
    return adjMatrix[src][dest];
}

void AdjacencyMatrix::addEdge(int src, int dest, int weight)
{
    adjMatrix[src][dest] = weight;
}

void AdjacencyMatrix::removeEdge(int src, int dest)
{
    adjMatrix[src][dest] = initialValue;
}