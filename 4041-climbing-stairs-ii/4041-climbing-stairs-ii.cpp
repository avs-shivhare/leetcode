class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp[100005];
        for(int i = 0; i<=n; i++) dp[i] = 1e9;
        dp[0] = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<4; j++) {
                if(i+j <= n) {
                    //cout<<(costs[i+j-1]+(j*j)+dp[i])<<" "<<i<<" "<<j<<endl;
                    dp[i+j] = min(costs[i+j-1]+(j*j)+dp[i],dp[i+j]);
                }
            }
        }
        // for(int i = 0; i<=n; i++) cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[n];
    }
};