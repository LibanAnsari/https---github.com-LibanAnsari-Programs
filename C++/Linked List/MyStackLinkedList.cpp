#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
    StackNode(int a) : data(a), next(NULL) {}
};

class MyStack
{
private:
    StackNode *top;

public:
    MyStack() { top = NULL; }

    void push(int x)
    {
        StackNode *n = new StackNode(x);
        n->next = top;
        top = n;
    }

    int pop()
    {
        if (top == NULL)
        {
            return -1;
        }
        else
        {
            int res = top->data;
            StackNode *todelete = top;
            top = top->next;
            delete todelete;
            return res;
        }
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        StackNode *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    MyStack stack;

    cout << "Pushing elements onto the stack." << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();

    cout << "Popping elements from the stack." << endl;
    cout << "Popped element: " << stack.pop() << endl;
    stack.display();

    cout << "Pushing another element onto the stack." << endl;
    stack.push(40);
    stack.display();

    cout << "Popping remaining elements from the stack." << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl;
    cout << "Popped element: " << stack.pop() << endl; // This should show the stack is empty
    stack.display();

    return 0;
}
