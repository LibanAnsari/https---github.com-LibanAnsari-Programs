#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int partition(int arr[] ,int l , int r){
        int pivot = arr[r];
        int i = l - 1;
        for(int j = l ; j < r ; j++){
            if(arr[j] < pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        i++;
        swap(arr[i],arr[r]);
        return i;
    }
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        while(l <= r){
            int p = partition(arr,l,r);
            if(p == k - 1){
                return arr[p];
            }else if(p > k - 1){
                r = p - 1;
            }else{
                l = p + 1;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    int arr[] = {12,23,54,56,78};
    Solution ob;
    cout << ob.kthSmallest(arr,0,4,2); 

    return 0;
}
