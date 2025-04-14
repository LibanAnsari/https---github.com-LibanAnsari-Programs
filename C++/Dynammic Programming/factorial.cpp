#include <iostream>
using namespace std;

class Solution1
{
    public:
    //Function to find the nth fibonacci number using bottom-up approach.
    long long findNthFibonacci(int n)
    {
        // Your Code Here
        long long fib[n + 1];
        
        fib[0] = 0; fib[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        
        return fib[n];
    }
};

class Solution2
{
    public:
    //Function to find the nth fibonacci number using top-down approach.
    long long findNthFibonacci(int n, long long int dp[])
    {
        // Your Code Here
        if(dp[n] != 0) return dp[n];
        
        if(n == 0 or n == 1) return n;
        
        return dp[n] = findNthFibonacci(n - 1, dp) + findNthFibonacci(n - 2, dp);
        
    }

};

int main(int argc, char const *argv[])
{
    Solution1 obj;

    cout << obj.findNthFibonacci(5);

    return 0;
}
