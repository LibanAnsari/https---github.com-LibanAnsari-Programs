#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

pair<int, int> findRepeatingElement(vector<int>& arr, int n) {
    unordered_set<int> seen;
    int duplicate = -1;

    // Find the duplicate using unordered_set
    for (int num : arr) {
        if (seen.find(num) != seen.end()) {
            duplicate = num;
            break;
        }
        seen.insert(num);
    }

    // If no duplicate was found
    if (duplicate == -1) {
        return {-1, -1};
    }

    // Count occurrences of the duplicate element
    int count = 0;
    for (int num : arr) {
        if (num == duplicate) {
            count++;
        }
    }

    return {duplicate, count};
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = findRepeatingElement(arr, n);
    cout << result.first << " " << result.second << endl;

    return 0;
}
