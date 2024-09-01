#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }

    // Function to push an element x into the queue.
    void enqueue(int x)
    {
        // Check if the queue is full
        if ((rear + 1) % 100005 == front)
        {
            // Queue is full
            cout << "Queue is full. Cannot push " << x << std::endl;
            return;
        }
        arr[rear] = x;
        rear = (rear + 1) % 100005;
    }

    // Function to pop an element from the queue and return that element.
    int dequeue()
    {
        // Check if the queue is empty
        if (front == rear)
        {
            // Queue is empty
            cout << "Queue is empty. Cannot pop." << std::endl;
            return -1;
        }
        int element = arr[front];
        front = (front + 1) % 100005;
        return element;
    }

    // Function to display all elements in the queue.
    void display()
    {
        if (front == rear)
        {
            // Queue is empty
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (i != rear)
        {
            std::cout << arr[i] << " ";
            i = (i + 1) % 100005;
        }
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    MyQueue ob;
    for (int i = 1; i <= 10; i++)
    {
        ob.enqueue(i);
    }
    ob.display();

    ob.dequeue();
    ob.dequeue();
    ob.display();
    return 0;
}
