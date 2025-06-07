class Solution {
public:
    long long dp[1001][501][4];
    long long find(int i,int k,int sp,vector<int> &prices) {
        if(k< 0) return -1e18;
        if(i == prices.size()) {
            if(sp == 0) return 0;
            return -1e18;
        }
        if(dp[i][k][sp] != -1) return dp[i][k][sp];
        long long t = -1e18,nt = -1e18;
        if(sp == 2) {
            t = -prices[i]+find(i+1,k-1,0,prices);
            nt = 0+find(i+1,k,sp,prices);
        }
        else if(sp == 1) {
            t = prices[i]+find(i+1,k-1,0,prices);
            nt = 0+find(i+1,k,sp,prices);
        }
        else {
            t = find(i+1,k,1,prices)-prices[i];
            t = max(t,prices[i]+find(i+1,k,2,prices));
            nt = find(i+1,k,sp,prices);
        }
        return dp[i][k][sp] = max(t,nt);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,k,0,prices);
    }
};