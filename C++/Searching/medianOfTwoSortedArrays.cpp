#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    if(n1 > n2) return findMedianSortedArrays(nums2, nums1); // always want num1 to be smaller

    int n = n1 + n2;
    int half = (n + 1)/2; // half elements in each set

    int low = 0 , high = n1; // for BS on nums1
    while(low <= high){
        int mid1 = (low + high) >> 1;
        int mid2 = half - mid1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // check if not out of bounds
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1-1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2-1];

        if(l1 <= r2 && l2 <= r1){ // answer found
            if(n % 2 == 1){
                return max(l1, l2);
            }else{
                return static_cast<double>((max(l1, l2) + min(r1, r2)) / 2.0);
            }
        }

        if(l1 > r2) high = mid1 - 1; // remove right half
        else low = mid1 + 1; // remove left half
    }
    return -1;
}

int main() {
    vector<int> nums1 = {1, 3, 8};
    vector<int> nums2 = {7, 9, 10, 11};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
