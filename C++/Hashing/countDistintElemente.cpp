#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n)
{
    unordered_set<int> hash;

    for (int i = 0; i < n; i++)
    {
        if(hash.find(arr[i]) == hash.end()){
            hash.insert(arr[i]);
        }
    }

    return hash.size();
}

int main(){
    int arr[] = {1,2,3,4,1,2,3,4,1,2,3};
    int n = sizeof(arr)/sizeof(int);
    cout << countDistinct(arr , n);
    return 0;
}