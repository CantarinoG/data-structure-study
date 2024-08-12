#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray<string> arr;
    arr.debug();
    arr.pushBack("Guilherme");
    cout << "Added Guilherme" << endl;
    arr.debug();
    arr.pushBack("Thais");
    cout << "Added Thais" << endl;
    arr.debug();
    arr.pushBack("Vitor");
    cout << "Added Vitor" << endl;
    arr.debug();
    arr.pushBack("Hygor");
    cout << "Added Hygor" << endl;
    arr.debug();
    arr.insertAt(3, "Arthur");
    cout << "Insert Arthur at 3" << endl;
    arr.debug();
    arr.deleteAt(3);
    cout << "Delete at 3" << endl;
    arr.debug();
    arr.popBack();
    cout << "Removing last element" << endl;
    arr.debug();
    arr.popBack();
    cout << "Removing last element" << endl;
    arr.debug();
    arr.popBack();
    cout << "Removing last element" << endl;
    arr.debug();
    return 0;
}