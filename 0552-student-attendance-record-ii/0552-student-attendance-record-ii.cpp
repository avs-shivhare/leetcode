class Solution {
public:
    int mod = 1e9+7;
    int f(int ind,int ap,int late,vector<vector<vector<int>>> &dp) {
        if(ind == 0) return 1;
        if(dp[ind][ap][late] != -1) return dp[ind][ap][late];
        int ans = 0;
        ans = f(ind-1,ap,0,dp)%mod;
        if(ap < 1) {
            ans = (ans + f(ind-1,ap+1,0,dp))%mod;
        }
        if(late <2) {
            ans = (ans+f(ind-1,ap,late+1,dp))%mod;
        }
        return dp[ind][ap][late] = ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(n,0,0,dp);
    }
};