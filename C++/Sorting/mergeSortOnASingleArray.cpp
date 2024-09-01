#include <bits/stdc++.h>
using namespace std;

void mergesort(int arr[] , int low , int mid , int high){
    // low <= mid < high
    int i = low;
    int j = mid + 1;
    while(i <= mid and j <= high){
        if(arr[i] <= arr[j]){
            cout << arr[i] << " ";
            i++;
        }else{
            cout << arr[j] << " ";
            j++;
        }
    }
    while(i <= mid){
        cout << arr[i] << " ";
        i++;
    }
    while(j <= high){
        cout << arr[j] << " ";
        j++;
    }

}

int main(int argc, char const *argv[])
{
    int arr[] = {10,15,20,11,30};
    mergesort(arr,0,2,4);
    return 0;
}
