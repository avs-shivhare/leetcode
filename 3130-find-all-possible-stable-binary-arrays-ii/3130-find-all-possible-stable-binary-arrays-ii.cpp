class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9+7;
        int dp[1001][1001][2];
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<=min(limit,max(one,zero)); i++) {
            dp[i][0][0] = 1;
            dp[0][i][1] = 1;
        }
        for(int i = 1; i<=zero; i++) {
            for(int j = 1; j<=one; j++) {
                dp[i][j][0] = (1ll*dp[i-1][j][0]+dp[i-1][j][1])%mod;
                dp[i][j][1] = (1ll*dp[i][j-1][1]+dp[i][j-1][0])%mod;
                if(i-1-limit >= 0) dp[i][j][0] = dp[i][j][0]-dp[i-1-limit][j][1];
                if(j-1-limit >= 0) dp[i][j][1] = dp[i][j][1]-dp[i][j-1-limit][0];
                if(dp[i][j][0] < 0) dp[i][j][0] += mod;
                if(dp[i][j][1] < 0) dp[i][j][1] += mod;
            }
        }
        return (1ll*dp[zero][one][1]+dp[zero][one][0])%mod;
    }
};