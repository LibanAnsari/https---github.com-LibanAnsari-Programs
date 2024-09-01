#include <bits/stdc++.h>
using namespace std;

int bSearch(int arr[] ,int low , int high, int x){
    if(low > high){
        return -1;
    }
    int mid = (low + high)/2;
    if(arr[mid] == x){
        return mid;
    }
    else if(x > arr[mid]){
        return bSearch(arr,mid+1,high,x);
    }else{
        return bSearch(arr,low,mid-1,x);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,15};

    cout << bSearch(arr,0,1,23);


    return 0;
}
