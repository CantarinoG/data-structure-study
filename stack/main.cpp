#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<char> stack(16);
    cout << stack.isEmpty() << endl;
    stack.push('a');
    cout << stack.isEmpty() << endl;
    cout << stack.peek() << endl;
    stack.push('b');
    stack.debug();
    cout << stack.pop() << endl;
    stack.debug();
    return 0;
}