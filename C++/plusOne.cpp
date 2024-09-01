//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// vector<int> plusOne(vector<int> &digits)
// {
//     int n = digits.size();
//     int d;
//     int num = 0;
//     for (int i = 0; i < n; i++)
//     {
//         num = num * 10 + digits[i];
//     }
//     num++;

//     vector<int> dig(n);
//     n--;
//     while (num != 0)
//     {
//         d = num % 10;
//         dig[n] = d;
//         num = num / 10;
//         n--;
//     }

//     return dig;
// }

int main()
{

    vector<int> digits = {9, 9, 9, 9};

    int n = digits.size();
    int d;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        num = num * 10 + digits[i];
    }
    num++;

    // cout << num;

    int temp = num;
    int count = 0;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }

    vector<int> dig(count);
    count--;

    while (num != 0)
    {
        d = num % 10;
        dig[count--] = d;
        num = num / 10;
    }

    for(int x : dig){
        cout << x << " ";
    }


    return 0;
}
