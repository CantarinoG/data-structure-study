#include <iostream>
#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
    AdjacencyMatrix graph(5);
    graph.debug();
    graph.addEdge(1, 1);
    graph.addEdge(1, 2, 3);
    graph.debug();
    cout << graph.getEdge(1, 2) << endl;
    graph.removeEdge(1, 2);
    graph.debug();
    return 0;
}