#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<vector<int>> &matrix, int R, int C) {
    int mi = matrix[0][0];
    int mx = matrix[0][C-1];
    
    // Finding the minimum and maximum elements in the matrix
    for (int i = 0; i < R; i++) {
        mi = min(mi, matrix[i][0]);
        mx = max(mx, matrix[i][C - 1]);
    }

    // Binary search for the median
    while (mi <= mx) {
        int mid = mi + (mx - mi) / 2;

        // Count the number of elements less than or equal to mid
        int freq = 0;
        for (int i = 0; i < R; i++) {
            freq += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        // If freq is more than or equal to half of the matrix elements,
        // search on the left side to find the median
        if (freq >= (R * C + 1) / 2) {
            mx = mid - 1;
        } else {
            mi = mid + 1;
        }
    }
    return mi;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    int R = 3; // Number of rows
    int C = 3; // Number of columns

    // Calculating the median
    int result = median(matrix, R, C);

    // Output the result
    cout << "The median is: " << result << endl;

    return 0;
}
