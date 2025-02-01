#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum that starts and ends with the same element
long maximum_sum(vector<long>& arr, int n) {
    // Compute prefix sums
    vector<long> prefix_sum(n, 0);
    prefix_sum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
    
    unordered_map<long, int> first_occurrence; // Maps element to its first occurrence index
    long max_sum = 0;
    
    // Find the maximum single element to consider single-element subarrays
    long single_max = arr[0];
    for(int i = 1; i < n; i++) {
        single_max = max(single_max, arr[i]);
    }
    max_sum = single_max;
    
    // Iterate through the array to find maximum subarray sum
    for(int i = 0; i < n; i++) {
        if(first_occurrence.find(arr[i]) == first_occurrence.end()) {
            // If element is seen for the first time, store its index
            first_occurrence[arr[i]] = i;
        }
        else {
            // If element has been seen before, calculate the sum from first occurrence to current index
            int start = first_occurrence[arr[i]];
            long current_sum = prefix_sum[i] - (start > 0 ? prefix_sum[start-1] : 0);
            max_sum = max(max_sum, current_sum);
        }
    }
    
    return max_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N; // Read the number of elements
    
    vector<long> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i]; // Read the array elements
    }
    
    // Call the maximum_sum function and print the result
    cout << maximum_sum(arr, N) << "\n";
    
    return 0;
}
