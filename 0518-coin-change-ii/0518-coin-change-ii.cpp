class Solution {
public:
    //recursion method with memorization
    int f(int ind,int target,vector<int> &coins,vector<vector<int>> &dp) {
        if(ind == 0) {
            if(target%coins[ind] == 0) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = f(ind-1,target,coins,dp);
        int take = 0;
        if(target >= coins[ind]) take = f(ind,target-coins[ind],coins,dp);
        return dp[ind][target] = take+notTake;
    }
    // int change(int target, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(target+1,-1));
    //     return f(n-1,target,coins,dp);
    // }


    //tabulation method
    // int change(int target, vector<int>& coins) {
    //     int n = coins.size();
    //     vector<vector<int>> dp(n,vector<int>(target+1,0));
    //     for(int i =0; i<= target;i++) {
    //         if(i%coins[0] == 0) dp[0][i] = 1;
    //         else dp[0][i] = 0;
    //     }
    //     for(int i =1; i<n; i++) {
    //         for(int j =0; j<=target; j++) {
    //             int notTake = dp[i-1][j];
    //             int take = 0;
    //             if(j>= coins[i]) take = dp[i][j-coins[i]];
    //             dp[i][j] = take+notTake;
    //         }
    //     }
    //     return dp[n-1][target];
    // }


    //space optimization
    int change(int target, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(target+1,0),curr(target+1,0);
        for(int i =0; i<= target;i++) {
            if(i%coins[0] == 0) prev[i] = 1;
            else prev[i] = 0;
        }
        for(int i =1; i<n; i++) {
            for(int j =0; j<=target; j++) {
                int notTake = prev[j];
                int take = 0;
                if(j>= coins[i]) take = curr[j-coins[i]];
                curr[j] = take+notTake;
            }
            prev = curr;
        }
        return prev[target];
    }
};