#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<char> list;
    list.insertAtEnd('a');
    list.insertAtEnd('b');
    list.insertAtBeginning('c');
    list.insertAtPosition('d', 2);
    list.debug();
    cout << "------------------------" << endl;
    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteFromPosition(1);
    list.debug();
    return 0;
}