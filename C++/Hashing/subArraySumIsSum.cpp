#include <bits/stdc++.h>
using namespace std;

bool subarray(int arr[], int n, int sum)
{
    unordered_set<int> hash;
    int prefixsum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixsum += arr[i];

        if (hash.find(prefixsum - sum) != hash.end())
        {
            return true;
        }
        if (prefixsum == sum)
        {
            return true;
        }
        hash.insert(prefixsum);
    }
    return false;
}

int main()
{
    int arr[6] = {5, 8, 0, 0, 3, -1};
    cout << subarray(arr, 6, 3);
}