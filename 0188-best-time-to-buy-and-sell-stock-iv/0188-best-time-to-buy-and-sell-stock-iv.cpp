class Solution {
public:
    //recursive solution
    // int f(int i,int j,int c,vector<vector<vector<int>>> &dp,vector<int> &prices,int &n) {
    //     if(i == n || c == 0) return 0;
    //     if(dp[i][j][c] != -1) return dp[i][j][c];
    //     if(j) {
    //         return dp[i][j][c] = max(-prices[i]+f(i+1,0,c,dp,prices,n),0+f(i+1,1,c,dp,prices,n));
    //     }
    //     return dp[i][j][c] = max(prices[i]+f(i+1,1,c-1,dp,prices,n),0+f(i+1,0,c,dp,prices,n));
    // }
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
    //     return f(0,1,k,dp,prices,n);
    // }

    //tabulation solution
    // int maxProfit(int k, vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
    //     for(int i =n-1; i>=0; i--) {
    //         for(int j =0; j<2; j++) {
    //             for(int c =1; c<=k; c++) {
    //                 if(j) {
    //                     dp[i][j][c] = max(-prices[i]+dp[i+1][0][c],0+dp[i+1][1][c]);
    //                 }
    //                 else dp[i][j][c] = max(prices[i]+dp[i+1][1][c-1],0+dp[i+1][0][c]);
    //             }
    //         }
    //     }
    //     return dp[0][1][k];
    // }

    //space optimization
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        for(int i =n-1; i>=0; i--) {
            for(int j =0; j<2; j++) {
                for(int c =1; c<=k; c++) {
                    if(j) {
                        curr[j][c] = max(-prices[i]+dp[0][c],0+dp[1][c]);
                    }
                    else curr[j][c] = max(prices[i]+dp[1][c-1],0+dp[0][c]);
                }
            }
            dp = curr;
        }
        return dp[1][k];
    }
};