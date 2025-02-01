#include <iostream>
#include <stack>
using namespace std;

void deleteMidHelper(stack<int> &s, int sizeOfStack, int curr) {
    // If the stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element
    int topElement = s.top();
    s.pop();

    // If the current index is the middle, do not push it back
    if(curr == sizeOfStack / 2) {
        return;
    }
    // Recursively call for the next element
    deleteMidHelper(s, sizeOfStack, curr + 1);
    // Push the element back if it is not the middle
    s.push(topElement);
}

void deleteMid(stack<int> &s) {
    int sizeOfStack = s.size(); // Get the size of the stack
    int curr = 0;               // Start from the top
    deleteMidHelper(s, sizeOfStack, curr);
}

void printStack(stack<int> s) {
    // Print stack elements from top to bottom
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Stack before deleting middle element: ";
    printStack(s); // Should print: 5 4 3 2 1 

    deleteMid(s); // Delete the middle element

    cout << "Stack after deleting middle element: ";
    printStack(s); // Should print: 5 4 2 1

    return 0;
}
