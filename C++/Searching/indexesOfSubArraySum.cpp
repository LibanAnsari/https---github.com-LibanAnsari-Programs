#include <bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target) {
    int start = 0;
    int sum = 0;
    
    for (int end = 0; end < arr.size(); end++) {
        sum += arr[end];

        while (sum > target && start <= end) {
            sum -= arr[start++];
        }

        if (sum == target) {
            return {start + 1, end + 1}; // 1-based index
        }
    }
    
    return {-1, -1}; // Return both values for consistency
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 5}; // Example array
    int target = 12; // Example target sum

    vector<int> result = subarraySum(arr, target);

    if (result[0] == -1) {
        cout << "No subarray with given sum found.\n";
    } else {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << "\n";
    }

    return 0;
}
