#include <iostream>
using namespace std;

int leftIndex(int n, int arr[], int x) {
    int ans = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoid overflow

        if (arr[mid] == x) {
            ans = mid;        // Found x, store index
            high = mid - 1;   // Move left to find earlier occurrence
        } else if (arr[mid] < x) {
            low = mid + 1;    // Search in right half
        } else {
            high = mid - 1;   // Search in left half
        }
    }
    return ans; // -1 if not found
}

int main() {
    int arr1[] = {1, 2, 2, 2, 3, 4, 5};  // Sorted array
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int x1 = 2;
    cout << "Leftmost index of " << x1 << " is: " << leftIndex(n1, arr1, x1) << endl;  // Output: 1

    return 0;
}
