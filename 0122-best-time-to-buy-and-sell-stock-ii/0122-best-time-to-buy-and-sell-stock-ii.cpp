class Solution {
public:
    // recursion with dp 
    // int f(int i,int j,vector<vector<int>> &dp,vector<int> &prices,int &n) {
    //     if(i == n) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int profit =0;
    //     if(j) {
    //         profit = max(-prices[i]+f(i+1,0,dp,prices,n),0+f(i+1,1,dp,prices,n));
    //     }
    //     else profit = max(prices[i]+f(i+1,1,dp,prices,n),0+f(i+1,0,dp,prices,n));
    //     return dp[i][j] = profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n,vector<int>(2,-1));
    //     return f(0,1,dp,prices,n);
    // }


    //tabulation with 2D array 
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<int>> dp(n+1,vector<int>(2,-1));
    //     dp[n][0] = dp[n][1] =0;
    //     for(int i = n-1; i>=0; i--) {
    //         for(int j =0; j<2; j++) {
    //             int profit =0;
    //             if(j) {
    //                 profit = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
    //             }
    //             else profit = max(prices[i]+dp[i+1][1],0+dp[i+1][0]);
    //             dp[i][j] = profit;
    //         }
    //     }
    //     return dp[0][1];
    // }

    //space optimization
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(2,0), curr(2,0);
        for(int i = n-1; i>=0; i--) {
            for(int j =0; j<2; j++) {
                int profit =0;
                if(j) {
                    profit = max(-prices[i]+dp[0],0+dp[1]);
                }
                else profit = max(prices[i]+dp[1],0+dp[0]);
                curr[j] = profit;
            }
            dp = curr;
        }
        return dp[1];
    }
};