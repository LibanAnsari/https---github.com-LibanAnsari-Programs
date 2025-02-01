#include<bits/stdc++.h>
using namespace std;

int kMostFrequent(int arr[], int n, int k) { 
    unordered_map<int, int> frequencyMap;
    
    // Step 1: Count frequencies of elements
    for (int i = 0; i < n; i++) {
        frequencyMap[arr[i]]++;
    }

    // Step 2: Use a max-heap to store frequencies in descending order
    priority_queue<int> maxHeap;
    for (auto entry : frequencyMap) {
        maxHeap.push(entry.second);
    }

    // Step 3: Sum the top K frequencies
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
    }
    
    return sum;
}

int main() {
    int arr1[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    cout << "Output for Example 1: " << kMostFrequent(arr1, n1, k1) << endl;

    int arr2[] = {3, 3, 3, 4, 1, 1, 6, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 2;
    cout << "Output for Example 2: " << kMostFrequent(arr2, n2, k2) << endl;

    return 0;
}