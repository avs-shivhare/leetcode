class Solution {
public:
    int dp[100001];
    int find(int i,vector<int> &cost) {
        if(i > cost.size()) {
            return 1e9;
        }
        if(i == cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = cost[i]+1+find(i+1,cost);
        if(i+1 < cost.size()) ans = min(ans,cost[i+1]+4+find(i+2,cost));
        if(i+2 < cost.size()) ans = min(ans,cost[i+2]+9+find(i+3,cost));
        return dp[i] = ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return find(0,costs);
    }
};