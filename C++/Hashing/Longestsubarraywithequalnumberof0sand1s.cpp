#include <bits/stdc++.h>
using namespace std;

int largestZeroSubarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;

    unordered_map<int, int> m;
    int sum = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            res = i + 1;

        if (m.find(sum + n) != m.end())
            res = max(res, i - m[sum + n]);
        else
            m[sum + n] = i;
    }

        return res;
}

int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestZeroSubarray(arr, n);
}