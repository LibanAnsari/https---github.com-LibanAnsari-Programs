#include <bits/stdc++.h>
using namespace std;

int binarysearch(const int arr[] , int n , int x){
    int res = -1;
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(x < arr[mid]){
            high = mid - 1;
        }else if(x > arr[mid]){
            low = mid + 1;
        }else{
            res = mid;
            break;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    // cout << "hello\n";
    int arr[] = {10,15};

    cout << binarysearch(arr,2,20);

    return 0;
}
