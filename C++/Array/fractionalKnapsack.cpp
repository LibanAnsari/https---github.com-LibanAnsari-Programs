#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparator function to sort items by value-to-weight ratio in descending order
bool MyCmp(pair<int, int> a, pair<int, int> b) {
    double r1 = static_cast<double>(a.first) / a.second;
    double r2 = static_cast<double>(b.first) / b.second;
    return r1 > r2;
}

// Function to calculate the maximum value we can carry with a given weight limit
double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w) {
    vector<pair<int, int>> v;
    int n = values.size();
    
    // Store items as pairs of (value, weight)
    for (int i = 0; i < n; i++) {
        v.push_back({values[i], weights[i]});
    }
    
    // Sort items based on value-to-weight ratio in descending order
    sort(v.begin(), v.end(), MyCmp);
    
    double res = 0.0; // Result to store maximum value
    
    for (int i = 0; i < n; i++) {
        if (v[i].second <= w) {
            // If full item weight can be taken, add its value
            res += v[i].first;
            w -= v[i].second;
        } else {
            // If only a fraction of the item can be taken, add proportional value
            res += (static_cast<double>(v[i].first) / v[i].second) * w;
            break;
        }
    }
    
    return res;
}

int main() {
    // Example inputs
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int w = 50; // Weight capacity of knapsack

    // Calculate maximum value possible with given weight capacity
    double maxValue = fractionalKnapsack(values, weights, w);

    // Output the result
    cout << "The maximum value in the knapsack is: " << maxValue << endl;

    return 0;
}
