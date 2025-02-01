#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> printNonRepeated(int arr[], int n) {
    // Using map to store the frequency of each element.
    unordered_map<int, int> mp;
    
    // Storing the frequency of each element in the map.
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    
    vector<int> v;
    // Iterating over the array elements.
    for (int i = 0; i < n; i++) {
        // If frequency of current element in map is 1,
        // then we store it in the vector.
        if (mp[arr[i]] == 1) {
            v.push_back(arr[i]);
        }
    }
    
    // Returning the vector of non-repeated elements.
    return v;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = printNonRepeated(arr, n);
    
    cout << "Non-repeated elements are: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
