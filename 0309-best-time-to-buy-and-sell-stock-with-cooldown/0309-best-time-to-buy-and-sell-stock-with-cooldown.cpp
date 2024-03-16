class Solution {
public:

//recusive solution with dp
//     int f(int i,int j,vector<vector<int>> &dp,vector<int> &prices,int &n) {
//         if(i >= n) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(j){
//             return dp[i][j] = max(-prices[i]+f(i+1,0,dp,prices,n),0+f(i+1,1,dp,prices,n));
//         }
//         return dp[i][j] = max(prices[i]+f(i+2,1,dp,prices,n),0+f(i+1,0,dp,prices,n));
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return f(0,1,dp,prices,n);
//     }

    //tabulation solution 
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i =n-1; i>=0; i--) {
            for(int j =0; j<2; j++) {
                if(j) dp[i][j] = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                else dp[i][j] =max(prices[i]+dp[i+2][1],0+dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};