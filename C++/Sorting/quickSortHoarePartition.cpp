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
            quickSort(arr, low, p);
            quickSort(arr, p + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        
        int pivot = arr[low];
        int i = low - 1;  // one before low
        int j = high + 1; // one after high
        while (true)
        {
            do
            {
                i++;
            } while (arr[i] < pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if (i >= j)
                return j;
            swap(arr[i], arr[j]);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution ob;
    int arr[] = {45,23,23,2,3};
    ob.quickSort(arr,0,4);
    
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
