#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if (low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        
        int pivot = arr[high];
        int i = low - 1; //one before low 
        for(int j = low ; j <= high - 1 ; j++){
            if(arr[j] < pivot){
                swap(arr[++i],arr[j]);
            }
        }
        swap(arr[i + 1],arr[high]);
        return i + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution ob;
    int arr[] = {45,23,25,2,3};
    ob.quickSort(arr,0,4);
    
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
