#include <bits/stdc++.h>
using namespace std;

class MyStack
{
public:
    const int stackMax = 100; // Define a constant for maximum stack size
    int stack[100];      // Declare the stack array with the defined size
    int top = -1;             // Initialize top to -1 to represent an empty stack

    void push(int data)
    {
        if (top == stackMax - 1)
        {
            cout << "Stack Full" << endl;
        }
        else
        {
            top++;
            stack[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            // Optionally: stack[top] = 0; // Not necessary, but can be used to clear data
            top--;
        }
    }

    void display()
    {
        if (top == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = top; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    // Example usage
    MyStack ob;
    ob.push(10);
    ob.push(20);
    ob.display(); // Output: 20 10
    ob.pop();
    ob.display(); // Output: 10
    ob.pop();
    ob.pop(); // Output: Stack Empty

    return 0;
}
