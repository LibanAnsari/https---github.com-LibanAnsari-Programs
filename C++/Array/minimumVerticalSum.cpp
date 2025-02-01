#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minimum_vertical_sum(vector<vector<int>> v) {
    int minsum = INT_MAX;
    int n1 = v.size();
    
    // Find the maximum number of columns in any row
    int maxcols = 0;
    for(auto &row : v){
        maxcols = max(maxcols, static_cast<int>(row.size())); 
    }
    
    // Calculate vertical sums for each column and find the minimum
    for(int j = 0 ; j < maxcols ; j++) {
        int colsum = 0;
        for(int i = 0 ; i < n1 ; i++) {
            if(j < v[i].size()) { // Check if the column exists in the current row
                colsum += v[i][j];
            }
        }
        minsum = min(minsum, colsum);
    }
    
    return minsum;
}

int main() {
    vector<vector<int>> v = {
        {1, 2, 3},
        {4, 5},
        {6, 7, 8, 9}
    };
    
    int result = minimum_vertical_sum(v);
    cout << "Minimum vertical sum: " << result << endl;

    return 0;
}
