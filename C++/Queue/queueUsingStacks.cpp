#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
private:
    stack<int> s1; // Stack for enqueue
    stack<int> s2; // Stack for dequeue

public:
    // Function to push an element in queue by using 2 stacks.
    void push(int x) {
        s1.push(x);
    }

    // Function to pop an element from queue by using 2 stacks.
    int pop() {
        // Transfer elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // If s2 is still empty after transfer, queue is empty
        if (s2.empty()) {
            return -1; // Queue is empty
        }

        // Pop the element from s2, which is the front of the queue
        int front = s2.top();
        s2.pop();
        return front;
    }
};

int main() {
    StackQueue q;

    // Sample operations
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Popped element: " << q.pop() << endl; // Should return 10
    cout << "Popped element: " << q.pop() << endl; // Should return 20

    q.push(40);
    
    cout << "Popped element: " << q.pop() << endl; // Should return 30
    cout << "Popped element: " << q.pop() << endl; // Should return 40
    cout << "Popped element: " << q.pop() << endl; // Should return -1 (queue empty)

    return 0;
}
