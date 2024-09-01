#include <iostream>
using namespace std;

// Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

// Structure of MyQueue
struct MyQueue
{
    QueueNode *front;
    QueueNode *rear;

    MyQueue()
    {
        front = rear = NULL;
    }

    // Function to push an element into the queue.
    void push(int x)
    {
        QueueNode *n = new QueueNode(x);
        if (front == NULL)
        {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    // Function to pop front element from the queue.
    int pop()
    {
        if (front == NULL)
        {
            return -1; // Queue is empty
        }
        int data = front->data;
        QueueNode *todelete = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL; // If the queue becomes empty
        }
        delete todelete;
        return data;
    }

    // Function to display elements in the queue.
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        QueueNode *temp = front;
        cout << "Queue elements: ";
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
    MyQueue q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Display queue elements
    q.display();

    // Pop elements from the queue
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;

    // Display queue elements again
    q.display();

    // Push another element
    q.push(40);
    q.display();

    // Pop remaining elements
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Popped element: " << q.pop() << endl; // This should show the queue is empty

    return 0;
}
