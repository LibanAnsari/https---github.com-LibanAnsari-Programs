#include <iostream>
#include <vector>
#include <cmath> // For abs()

using namespace std;

vector<int> findTwoRepeated(int arr[], int n) {
    vector<int> result;

    for (int i = 0; i < n + 2; i++) { // +2 since two elements are repeated
        int index = abs(arr[i]); // Get absolute value to find index

        if (arr[index] < 0) {
            // If already marked negative, it's a repeated number
            result.push_back(index);
        } else {
            // Mark the index as visited by making it negative
            arr[index] = -arr[index];
        }
    }

    return result;
    
}

int main() {
    int arr1[] = {1, 2, 1, 3, 4, 3};
    int n1 = 4;
    vector<int> res1 = findTwoRepeated(arr1, n1);
    cout << res1[0] << " " << res1[1] << endl; // Output: 1 3

    return 0;
}
