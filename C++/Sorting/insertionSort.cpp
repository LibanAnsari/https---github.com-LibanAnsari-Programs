#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[] , int n){
    for(int i = 1; i < n ; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {12,32,2,34,3};
    insertionSort(arr,5);

    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
