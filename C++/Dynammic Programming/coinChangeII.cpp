#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[], int n, int sum){
        
        vector<vector<long long>> dp(sum + 1, vector<long long>(n + 1, 0));
        
        for(int i = 0 ; i <= n ; i++) dp[0][i] = 1;
        
        for(int i = 1 ; i <= sum ; i++){
            for(int j = 1 ; j <= n ; j++){
                if(i < coins[j - 1]){
                    dp[i][j] = dp[i][j - 1];
                }else{
                    dp[i][j] = dp[i][j - 1] + dp[i - coins[j - 1]][j];
                }
            }
        }
        
        return dp[sum][n];
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


    cout << obj.numberOfWays(coins, numberOfCoins, value);
    
    
    return 0;
}
