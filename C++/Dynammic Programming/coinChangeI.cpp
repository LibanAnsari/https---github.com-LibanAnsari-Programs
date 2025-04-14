#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    long long minimumNumberOfCoins(int coins[],int n, int sum)
    {
        vector<long long> dp(sum + 1, LLONG_MAX);
        
        dp[0] = 0;
        
        for(int i = 1 ; i <= sum ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(coins[j - 1] <= i and dp[i - coins[j - 1]] != LLONG_MAX){
                    dp[i] = min(dp[i] , dp[i - coins[j - 1]] + 1);
                }
            }
        }
        
        return dp[sum] == LLONG_MAX ? -1 : dp[sum];
    }
};

int main(int argc, char const *argv[])
{
    Solution obj;

    // int value = 5;
    // int numberOfCoins = 3;
    // int coins[] = {3,6,3};

    int value = 10;
    int numberOfCoins = 4;
    int coins[] = {2, 5, 3, 6};

    if(obj.minimumNumberOfCoins(coins, numberOfCoins, value) == -1){
        cout << "Not Possible";
    }else{
        cout << obj.minimumNumberOfCoins(coins, numberOfCoins, value);
    }
    
    return 0;
}
