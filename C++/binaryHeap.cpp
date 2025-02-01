#include <bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int *harr;        // Pointer to array of elements in heap
    int capacity;     // Maximum possible size of the min heap
    int heap_size;    // Current number of elements in the min heap

    // Constructor to initialize a heap with a given capacity
    MinHeap(int cap) 
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    // Function to extract minimum value in heap and then to store 
    // the next minimum value at the first index.
    int extractMin() 
    {
        if (heap_size == 0) {
            return -1; // Heap is empty
        }
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }

        // Swap the root with the last element and reduce heap size
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;

        // Heapify the root
        MinHeapify(0);

        return root;
    }

    // Function to delete a key at ith index.
    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN); // Decrease the key to a very small value
        extractMin();            // Remove the minimum value
    }

    // Function to insert a value in Heap.
    void insertKey(int k) 
    {
        if (heap_size == capacity) {
            cout << "Heap overflow. Cannot insert key." << endl;
            return;
        }

        // Insert the new key at the end
        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // Function to decrease the value of key at index 'i' to new_val
    void decreaseKey(int i, int new_val) 
    {
        harr[i] = new_val;

        // Fix the min heap property if it is violated
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr[i], harr[parent(i)]);
            i = parent(i);
        }
    }

    // A utility function to heapify the subtree rooted with index i
    void MinHeapify(int i) 
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    // Utility functions to get the parent, left, and right child of a node
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }
};

// Driver code to test the MinHeap class
int main() 
{
    MinHeap h(11);  // Create a MinHeap of capacity 11

    // Inserting elements
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    // Displaying extracted minimum values
    cout << "Extracted min: " << h.extractMin() << endl; // Should be 2
    cout << "Min element: " << h.harr[0] << endl;        // Should be 4

    // Decreasing key and displaying updated minimum
    h.decreaseKey(2, 1);
    cout << "Min element after decreaseKey: " << h.harr[0] << endl; // Should be 1

    return 0;
}
