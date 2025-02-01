#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int KthLargest(vector<int> arr, int k) {
    // Create a max-heap (priority queue) with all elements in arr
    priority_queue<int> pq(arr.begin(), arr.end());
    
    // Remove the top element (largest) k - 1 times
    for (int i = 1; i < k; i++) {
        if (pq.empty()) {
            return -1;  // If k is larger than the array size
        }
        pq.pop();
    }
    
    // Return the k-th largest element
    return pq.top();
}

int main() {
    // Sample input
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;
    
    // Find the k-th largest element
    int result = KthLargest(arr, k);
    if(result == -1) {
        cout << "k is larger than the size of the array." << endl;
    } else {
        cout << "The " << k << "-th largest element is: " << result << endl;
    }

    return 0;
}
