#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    DynamicArray arr = DynamicArray();
    arr.debug();
    arr.pushBack(25);
    cout << "Added 25" << endl;
    arr.debug();
    arr.pushBack(50);
    cout << "Added 50" << endl;
    arr.debug();
    arr.pushBack(75);
    cout << "Added 75" << endl;
    arr.debug();
    arr.pushBack(100);
    cout << "Added 100" << endl;
    arr.debug();
    arr.insertAt(3, 1000);
    cout << "Insert 1000 at 3" << endl;
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