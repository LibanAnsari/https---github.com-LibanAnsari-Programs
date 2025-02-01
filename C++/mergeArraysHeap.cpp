#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void mergeArrays(int* a, int n, int* b, int m) 
{ 
    // Build a min-heap for array `b`
    make_heap(b, b + m, greater<int>());

    // Iterate over each element in array `a`
    for (int i = 0; i < n; i++) {
        // If the current element in `a` is greater than the smallest in `b`
        if (a[i] > b[0]) {
            // Replace the smallest in `b` with `a[i]` to maintain order
            pop_heap(b, b + m, greater<int>());
            swap(a[i], b[m - 1]);
            push_heap(b, b + m, greater<int>());
        }
    }

    // Sort array `b` to maintain the sorted order in both `a` and `b`
    sort(b, b + m);
}

int main() {
    int a[] = {1, 5, 9, 10, 15, 20};
    int b[] = {2, 3, 8, 13};
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);

    mergeArrays(a, n, b, m);

    cout << "Array a after merging: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Array b after merging: ";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
