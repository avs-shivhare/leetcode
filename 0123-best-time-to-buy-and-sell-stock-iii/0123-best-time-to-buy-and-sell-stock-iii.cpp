class Solution {
public:
    //recusive solution with 3D dp
    // int f(int i,int j,int c,vector<int> &prices,int &n,vector<vector<vector<int>>> &dp) {
    //     if(i == n || c == 0) return 0;
    //     if(dp[i][j][c] != -1) return dp[i][j][c];
    //     if(j) {
    //         return dp[i][j][c] = max(-prices[i]+f(i+1,0,c,prices,n,dp),0+f(i+1,1,c,prices,n,dp));
    //     }
    //     else return dp[i][j][c] = max(prices[i]+f(i+1,1,c-1,prices,n,dp),0+f(i+1,0,c,prices,n,dp));
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //     return f(0,1,2,prices,n,dp);
    // }

    //tabulation with 3D array
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //     for(int i = n-1;i >=0; i--) {
    //         for(int j =0; j<2; j++) {
    //             for(int c = 1; c<3; c++) {
    //                 if(j) {
    //                     dp[i][j][c] = max(-prices[i]+dp[i+1][0][c],0+dp[i+1][1][c]);
    //                 }
    //                 else dp[i][j][c] = max(prices[i]+dp[i+1][1][c-1],0+dp[i+1][0][c]);
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }

    //space optimization 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2,vector<int>(3,0)), curr(2,vector<int>(3,0));
        for(int i = n-1;i >=0; i--) {
            for(int j =0; j<2; j++) {
                for(int c = 1; c<3; c++) {
                    if(j) {
                        curr[j][c] = max(-prices[i]+dp[0][c],0+dp[1][c]);
                    }
                    else curr[j][c] = max(prices[i]+dp[1][c-1],0+dp[0][c]);
                }
            }
            dp = curr;
        }
        return dp[1][2];
    }
};