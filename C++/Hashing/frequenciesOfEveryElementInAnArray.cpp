#include <bits/stdc++.h>
using namespace std;

void frequencies(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
            m[arr[i]]++;
        else
            m.insert({arr[i], 1});
    }

    for (const auto &pair : m)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    frequencies(arr, n);
    return 0;
}