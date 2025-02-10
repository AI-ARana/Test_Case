// Given a stack, how to reverse the elements of stack by using only stack operations? 

#include <iostream>
#include <stack>

using namespace std;

// Function to insert an element at the bottom of a stack
void insertAtBottom(stack<int>& s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }

    int topValue = s.top();
    s.pop();
    insertAtBottom(s, value);
    s.push(topValue);
}

// Function to reverse a stack using recursion
void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }

    int topValue = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, topValue);
}

// Function to print the stack
void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    system("cls");
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Original Stack: ";
    printStack(s);

    reverseStack(s);

    cout << "Reversed Stack: ";
    printStack(s);

    return 0;
}
