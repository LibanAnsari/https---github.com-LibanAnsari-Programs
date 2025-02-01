#include <iostream>
using namespace std;

int minNumber(int arr[], int low, int high) {
    while (low < high) {  // Use < instead of <= to prevent unnecessary checks
        int mid = low + (high - low) / 2;

        // If mid element is less than the high element, the minimum is on the left (including mid)
        if (arr[mid] < arr[high]) {
            high = mid;
        }
        // Otherwise, the minimum is on the right (excluding mid)
        else {
            low = mid + 1;
        }
    }
    return arr[low]; // The min element is at the `low` index after the loop
}

int main() {
    int arr1[] = {3, 4, 5, 1, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Minimum element: " << minNumber(arr1, 0, n1 - 1) << endl;  // Output: 1
    
    return 0;
}
