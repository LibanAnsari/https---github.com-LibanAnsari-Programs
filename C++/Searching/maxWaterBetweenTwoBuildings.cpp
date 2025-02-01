#include <iostream>
#include <algorithm> // For min() and max() functions

using namespace std;

// Function to find the maximum water that can be trapped
int maxWater(int height[], int n) {
    int low = 0, high = n - 1;
    int res = -1;
    while (low < high) {
        int small = min(height[low], height[high]);
        int curr = small * (high - low - 1);
        
        res = max(res, curr);
        
        if (height[low] >= height[high]) {
            high--;
        } else {
            low++;
        }
    }
    return res;
}

int main() {
    // Example array representing heights of bars
    int height[] = {1, 3, 2, 4, 5, 2, 6};
    int n = sizeof(height) / sizeof(height[0]);

    // Call the maxWater function and store the result
    int result = maxWater(height, n);

    // Output the result
    cout << "Maximum water that can be trapped: " << result << endl; // Output: 8

    return 0;
}