#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int k, int ans){
    int sum = 0;
    int req = 1;
    
    for(int i = 0 ; i < arr.size() ; i++){
        if(sum + arr[i] > ans){
            req++;
            sum = arr[i];
        }else{
            sum += arr[i];
        }
    }
    return (req <= k);
}

int findPages(vector<int> &arr, int k) {
    if (k > arr.size()) return -1;  // More students than books → impossible

    int sum = accumulate(arr.begin(), arr.end(), 0);
    int mx = *max_element(arr.begin(), arr.end());

    int low = mx, high = sum, res = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (isPossible(arr, k, mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << findPages(arr, k) << endl;  // Expected Output: 113
    return 0;
}
