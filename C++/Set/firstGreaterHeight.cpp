#include <bits/stdc++.h>
using namespace std;

vector<int> greater_height(vector<int> v) {
    int n = v.size();
    set<int> s;
    vector<int> res(n);
    
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(v[i]);  // Find first element strictly greater than v[i]
        if (it == s.end()) {
            res[i] = -1;  // No greater element found
        } else {
            res[i] = *it;  // Element found
        }
        s.insert(v[i]);  // Insert current element into set for future comparisons
    }
    return res;
}

int main() {
    vector<int> heights = {10, 3, 6, 8, 4, 2};
    for (int x : heights) {
        cout << x << " ";
    }
    cout << endl;

    vector<int> result = greater_height(heights);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}