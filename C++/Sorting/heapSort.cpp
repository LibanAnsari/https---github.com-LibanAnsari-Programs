#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[] , int n , int i){
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if(l < n and arr[l] > arr[largest]){
        largest = l;
    }
    if(r < n and arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void buildHeap(int arr[] , int n){
    for(int i = (n-2)/2 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    buildHeap(arr,n);
    for(int i = n - 1 ; i > 0 ; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main()
{
    int arr[] = {45,23,25,2,3};
    heapSort(arr,5);
    
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
