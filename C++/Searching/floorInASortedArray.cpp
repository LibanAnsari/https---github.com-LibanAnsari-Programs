#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findFloor(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        int floorIndex = -1; // Default value if no floor exists

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] <= k) {
                floorIndex = mid;  // Possible floor found
                low = mid + 1;      // Look for a larger floor
            } else {
                high = mid - 1;     // Discard the right half
            }
        }

        return floorIndex;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    int k = 5;

    int result = sol.findFloor(arr, k);
    cout << "Floor index: " << result << endl;

    return 0;
}
