#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<char> queue(16);
    queue.debug();
    cout << "isEmpty: ";
    cout << queue.isEmpty() << endl;
    cout << "Added 'a'" << endl;
    queue.enqueue('a'); // Typing this shit is a nightmare
    cout << "isEmpty: ";
    cout << queue.isEmpty() << endl;
    queue.debug();
    cout << "Added 'b'" << endl;
    queue.enqueue('b');
    queue.debug();
    cout << "Added 'c'" << endl;
    queue.enqueue('c');
    queue.debug();
    cout << "Removed" << endl;
    queue.dequeue();
    queue.debug();
    cout << "Removed" << endl;
    queue.dequeue();
    queue.debug();
    cout << "Removed" << endl;
    queue.dequeue();
    queue.debug();
    return 0;
}