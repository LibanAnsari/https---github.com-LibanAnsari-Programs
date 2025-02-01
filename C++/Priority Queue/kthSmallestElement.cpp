#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallest(int arr[], int n, int k) {
    // Create a min-heap with all elements in arr
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    
    // Remove the smallest element k - 1 times
    for (int i = 1; i < k; i++) {
        if (pq.empty()) {
            return -1;  // If k is larger than the array size
        }
        pq.pop();
    }
    
    // Return the k-th smallest element
    return pq.top();
}

int main() {
    // Sample input
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    // Find the k-th smallest element
    int result = kthSmallest(arr, n, k);
    if (result == -1) {
        cout << "k is larger than the size of the array." << endl;
    } else {
        cout << "The " << k << "-th smallest element is: " << result << endl;
    }

    return 0;
}
