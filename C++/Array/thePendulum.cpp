#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

vector<int> thePendulum(vector<int> v) {
    // Sort the input vector
    sort(v.begin(), v.end());
    
    list<int> ans;
    int trigger = 0;

    // Arrange elements in a "pendulum" pattern
    for (int i = 0; i < v.size();) {
        if (trigger == 0) {
            // Place two elements at the front if available
            ans.push_front(v[i++]);
            if (i < v.size()) {
                ans.push_front(v[i++]);
            }
            trigger = 1; // Switch to back placement
        } else {
            // Place two elements at the back if available
            ans.push_back(v[i++]);
            if (i < v.size()) {
                ans.push_back(v[i++]);
            }
            trigger = 0; // Switch to front placement
        }
    }

    // Copy list contents back into the vector
    v.clear();
    for (auto &element : ans) {
        v.push_back(element);
    }
    
    return v;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> result = thePendulum(v);

    cout << "Pendulum arrangement: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
