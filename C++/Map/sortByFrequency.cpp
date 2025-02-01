#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> sortByFreq(vector<int>& arr) {
    vector<int> res;
    int n = arr.size();
    unordered_map<int, int> m;
    
    // Count frequency of each element
    for (auto x : arr) {
        m[x]++;
    }
    
    // Store elements in a frequency array where index is the frequency
    vector<int> freq[n + 1];
    for (auto x : m) {
        freq[x.second].push_back(x.first);
    }
    
    // Traverse frequencies from high to low
    for (int i = n; i >= 0; i--) {
        // Sort elements with the same frequency in ascending order
        sort(freq[i].begin(), freq[i].end());
        for (auto x : freq[i]) {
            // Add each element `i` times to the result
            for (int j = 0; j < i; j++) {
                res.push_back(x);
            }
        }
    }
    return res;
}

int main() {
    // Example input array
    vector<int> arr = {4, 5, 6, 5, 4, 3};

    // Call sortByFreq to sort by frequency and get the result
    vector<int> sortedArr = sortByFreq(arr);

    // Output the sorted array
    cout << "Array sorted by frequency: ";
    for (int x : sortedArr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
