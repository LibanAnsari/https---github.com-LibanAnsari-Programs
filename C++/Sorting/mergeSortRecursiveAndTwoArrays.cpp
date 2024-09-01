#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
        {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++)
        {
            R[j] = arr[m + j + 1];
        }

        int i = 0, j = 0;
        int k = l;
        while (i < n1 and j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k++] = L[i++];
            }
            else
            {
                arr[k++] = R[j++];
            }
        }
        while (i < n1)
        {
            arr[k++] = L[i++];
        }
        while (j < n2)
        {
            arr[k++] = R[j++];
        }
    }

public:
    void mergeSort(int arr[], int l, int r)
    {
        // code here
        if (l < r)
        {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution ob;
    int arr[] = {45,23,23,2,3};
    ob.mergeSort(arr,0,4);
    
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
