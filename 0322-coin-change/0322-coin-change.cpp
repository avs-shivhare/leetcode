class Solution {
public:


    //recursion method with memorization
    int f(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp) {
        if(ind == 0) {
            if(amount%coins[ind] == 0) {
                return amount/coins[ind];
            }
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int notTake = 0+f(ind-1,amount,coins,dp);
        int take = INT_MAX;
        if(coins[ind] <= amount) {
            take = 1+f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount] = min(take,notTake);
    }


    //Tabulation method
    // int coinChange(vector<int>& coins, int amount) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,0));
    //     for(int i =0;i<= amount; i++) {
    //         if(i%coins[0] == 0) {
    //             dp[0][i] = i/coins[0];
    //         }
    //         else dp[0][i] = 1e9;
    //     }
    //     for(int i =1; i<n; i++) {
    //         for(int j =0; j<= amount; j++) {
    //             int notTake = 0+dp[i-1][j];
    //             int take = INT_MAX;
    //             if(j>= coins[i]) take = 1+dp[i][j-coins[i]];
    //             dp[i][j] = min(take,notTake);
    //         }
    //     }
    //     int ans= dp[n-1][amount];
    //     if(ans >= 1e9) return -1;
    //     return ans;
    // }

    
    //Space optimization method
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0), curr(amount+1,0);
        for(int i =0;i<= amount; i++) {
            if(i%coins[0] == 0) {
                prev[i] = i/coins[0];
            }
            else prev[i] = 1e9;
        }
        for(int i =1; i<n; i++) {
            for(int j =0; j<= amount; j++) {
                int notTake = 0+prev[j];
                int take = INT_MAX;
                if(j>= coins[i]) take = 1+curr[j-coins[i]];
                curr[j] = min(take,notTake);
            }
            prev = curr;
        }
        int ans= prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};