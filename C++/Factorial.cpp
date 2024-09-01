//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int factorial(int N)
    {
        if (N > 1)
        {
            return N * factorial(N - 1);
        }
        else
        {
            return 1;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int num;
    cout << "Enter the number: ";
    cin >> num;
    Solution ob;
    cout << "The factoral is: " << ob.factorial(num) << endl;
    return 0;
}
// } Driver Code Ends
