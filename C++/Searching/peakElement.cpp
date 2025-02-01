#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > arr[mid + 1]) { 
                // Peak is on the left or at mid
                right = mid;
            } else {  
                // Peak is on the right
                left = mid + 1;
            }
        }

        return left; // `left` or `right` will point to a peak element
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10, 20, 15, 2, 23, 90, 80};

    int peakIndex = sol.findPeakElement(arr);
    cout << "Peak Element Index: " << peakIndex << endl;
    cout << "Peak Element: " << arr[peakIndex] << endl;

    return 0;
}
