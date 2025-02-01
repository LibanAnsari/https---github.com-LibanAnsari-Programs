#include <bits/stdc++.h>
using namespace std;

int subarray(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    int prefixsum = 0;
    int res;
    for (int i = 0; i < n; i++)
    {
        prefixsum += arr[i];

        if (prefixsum == sum)
        {
            res = i + 1;
        }
        if (m.find(prefixsum - sum) == m.end())
        {
            m.insert({prefixsum, i});
        }
        if (m.find(prefixsum - sum) != m.end())
        {
            res = max(res, i - m[prefixsum - sum]);
        }
    }
    return res;
}

int main()
{
    int arr[6] = {5, 8, 1, 4, 3, -1};
    cout << subarray(arr, 6, 5);
}