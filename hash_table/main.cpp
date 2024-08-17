#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    string name = "Guilherme";
    string name2 = "Thais";
    HashTable ht(10);
    ht.insert(100, name);
    ht.insert(99, name);
    ht.insert(99, name2);
    ht.debug();
    string searched;
    ht.search(99, searched);
    cout << searched << endl;
    ht.remove(99);
    ht.debug();
    return 0;
}