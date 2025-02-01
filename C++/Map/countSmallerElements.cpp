#include <iostream>
#include <vector>
#include <map>
using namespace std;

void mergeAndCount(vector<pair<int, int>>& arr, int left, int mid, int right, map<int, int>& countMap) {
    int i = left, j = mid + 1, k = 0;
    vector<pair<int, int>> temp(right - left + 1);
    int rightCount = 0; // Count of smaller elements on the right side

    // Merge the two halves and count smaller elements
    while (i <= mid && j <= right) {
        if (arr[i].first <= arr[j].first) {
            // Add the count of smaller elements encountered so far
            countMap[arr[i].second] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        countMap[arr[i].second] += rightCount;
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right half
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy sorted elements back into original array
    for (int i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Modified merge sort to sort and count smaller elements
void mergeSortAndCount(vector<pair<int, int>>& arr, int left, int right, map<int, int>& countMap) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortAndCount(arr, left, mid, countMap);
        mergeSortAndCount(arr, mid + 1, right, countMap);
        mergeAndCount(arr, left, mid, right, countMap);
    }
}
  
vector<int> constructLowerArray(vector<int>& arr) {
    int n = arr.size();
    map<int, int> countMap; // To store the result for each index
    vector<pair<int, int>> indexedArr(n);
    
    // Pair each element with its index
    for (int i = 0; i < n; i++) {
        indexedArr[i] = {arr[i], i};
    }

    // Sort and count using modified merge sort
    mergeSortAndCount(indexedArr, 0, n - 1, countMap);

    // Prepare the output array using the countMap
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = countMap[i];
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = constructLowerArray(arr);

    cout << "Count of smaller elements to the right for each element: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
