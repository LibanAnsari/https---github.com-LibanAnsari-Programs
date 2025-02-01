#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> map; // To track unique elements
    vector<int> result;      // To store the result without duplicates

    for (int num : arr) {
        // If the number has not been map, add it to the set and result
        if (map.find(num) == map.end()) {
            map.insert(num);
            result.push_back(num);
        }
    }
    
    return result;
}

int main() {
    // Sample input
    vector<int> arr = {1, 2, 3, 1, 4, 2, 5, 3};

    vector<int> uniqueArr = removeDuplicates(arr);

    // Output the result
    cout << "Array after removing duplicates: ";
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
