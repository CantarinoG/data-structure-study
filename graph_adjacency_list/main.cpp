#include "AdjacencyList.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    AdjacencyList list(4);
    list.debug();
    cout << endl;
    list.addEdge(0, 3);
    list.addEdge(0, 2);
    list.addEdge(0, 3);
    list.debug();
    vector<int> firstIndexEdges = list.getEdges(0);
    cout << "List in 0: ";
    for (int i = 0; i < firstIndexEdges.size(); i++)
    {
        cout << firstIndexEdges[i] << "\t";
    }
    cout << endl;
    cout << "Is there edge between 0 and 1: " << list.isThereEdge(0, 1) << endl;
    list.removeEdge(0, 2);
    list.debug();

    return 0;
}