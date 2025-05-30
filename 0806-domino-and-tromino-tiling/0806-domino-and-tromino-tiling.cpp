class Solution {
public:
    int numTilings(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<long long> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        int mod = 1e9+7;
        for(int i= 3; i<=n; i++) {
            dp[i] = (2ll*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n];
    }
};