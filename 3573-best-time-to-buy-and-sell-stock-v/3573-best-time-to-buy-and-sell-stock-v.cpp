class Solution {
public:
    long long dp[1001][1501][3];
    long long find(int i,int k,int t,vector<int> &prices) {
        if(k < 0) return -1e18;
        if(i >= prices.size()) {
            if(t) return -1e18;
            return 0;
        }
        if(dp[i][k][t] != -1) return dp[i][k][t];
        long long take = -1e18,notTake = -1e18,sp = -1e18;
        if(t == 1) {
            take = prices[i]+find(i+1,k-1,0,prices);
        }
        else if(t == 2) {
            sp = find(i+1,k-1,0,prices)-prices[i];
        }
        else {
            take = find(i+1,k,1,prices)-prices[i];
            sp = prices[i]+find(i+1,k,2,prices);
        }
        notTake = find(i+1,k,t,prices);
        return dp[i][k][t] = max({take,notTake,sp});
    }
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,k,0,prices);
    }
};