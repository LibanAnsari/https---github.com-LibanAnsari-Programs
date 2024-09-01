#include <bits/stdc++.h>
using namespace std;

string countSort(string arr)
{
    int count[26] = {0};
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - 'a']++;
    }

    for (int i = 1; i < 26; i++)
    {
        count[i] = count[i - 1] + count[i];
    }

    vector<char> output(n);
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - 'a'] - 1] = arr[i];
        count[arr[i] - 'a']--;
    }

    return string(output.begin(), output.end());
}

int main(int argc, char const *argv[])
{
    cout << countSort("xbeastmex");
    return 0;
}
