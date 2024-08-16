#include "AdjacencyList.h"
#include "../linked_list/LinkedList.h"
#include <iostream>
#include <vector>

using namespace std;

AdjacencyList::AdjacencyList(int vertices)
{
    this->vertices = vertices;
    adjList = new vector<int>[vertices];
}

AdjacencyList::~AdjacencyList()
{
    delete[] adjList;
}

void AdjacencyList::debug()
{
    for (int i = 0; i < vertices; i++)
    {
        cout << i << ": [";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void AdjacencyList::handleUnallowedValue(int value)
{
    if (value > vertices - 1)
    {
        throw runtime_error("Value bigger than the number of vertices.");
    }
    else if (value < 0)
    {
        throw runtime_error("Negative index.");
    }
}

vector<int> AdjacencyList::getEdges(int src)
{
    return adjList[src];
}

int AdjacencyList::isThereEdge(int src, int dest)
{
    vector<int> indexVector = adjList[src];

    for (int i = 0; i < indexVector.size(); i++)
    {
        if (indexVector[i] == dest)
        {
            return 1;
        }
    }
    return 0;
}

void AdjacencyList::addEdge(int src, int dest)
{
    handleUnallowedValue(src);
    handleUnallowedValue(dest);

    if (isThereEdge(src, dest))
    {
        return;
    }

    adjList[src].push_back(dest);
}

int AdjacencyList::getVectorIndex(int src, int dest)
{
    handleUnallowedValue(src);
    handleUnallowedValue(dest);

    if (!isThereEdge(src, dest))
    {
        return -1;
    }

    for (int i = 0; i < adjList[src].size(); i++)
    {
        if (adjList[src][i] == dest)
        {
            return i;
        }
    }

    return -1;
}

void AdjacencyList::removeEdge(int src, int dest)
{

    handleUnallowedValue(src);
    handleUnallowedValue(dest);

    if (!isThereEdge(src, dest))
    {
        return;
    }

    int indexToRemove = getVectorIndex(src, dest);
    if (indexToRemove != -1)
    {
        adjList[src].erase(adjList[src].begin() + indexToRemove);
    }
}
