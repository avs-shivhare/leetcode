class Solution {
public:
    //recursive solution with dp
    // int f(int i,int j,vector<vector<int>> &dp,vector<int> &prices,int &fee,int &n) {
    //     if(i == n) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(j) {
    //         return dp[i][j] =max(-prices[i]+f(i+1,0,dp,prices,fee,n)-fee,0+f(i+1,1,dp,prices,fee,n));
    //     }
    //     return dp[i][j] =max(prices[i]+f(i+1,1,dp,prices,fee,n),0+f(i+1,0,dp,prices,fee,n));
    // }
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return f(0,1,dp,prices,fee,n);
    // }

    //tabulation with 2d array
    // int maxProfit(vector<int>& prices, int fee) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,0));
    //     for(int i = n-1; i>=0; i--) {
    //         for(int j =0; j<2; j++) {
    //             if(j) dp[i][j] = max(-prices[i]+dp[i+1][0]-fee,0+dp[i+1][1]);
    //             else dp[i][j] = max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
    //         }
    //     }
    //     return dp[0][1];
    // }
 
    //space optimization
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(2,0),curr(2,0);
        for(int i = n-1; i>=0; i--) {
            for(int j =0; j<2; j++) {
                if(j) curr[j] = max(-prices[i]+dp[0]-fee,0+dp[1]);
                else curr[j] = max(prices[i]+dp[1],0+dp[0]);
            }
            dp = curr;
        }
        return dp[1];
    }
};