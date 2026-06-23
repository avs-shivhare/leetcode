class Solution {
public:
    long long mod = 1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int dp[2002][2];
        memset(dp,0,sizeof(dp));
        for(int i = l; i<=r; i++) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        for(int i = n-2; i>=0; i--) {
            //cout<<i<<" -> "<<endl;
            int newdp[2002][2];
            memset(newdp,0,sizeof(newdp));
            for(int j = l+1; j<=r; j++) {
                dp[j][0] = (dp[j][0]+dp[j-1][0])%mod;
                dp[j][1] = (dp[j][1]+dp[j-1][1])%mod;
            }
            // for(int j = l; j<=r; j++) {
            //     cout<<dp[j][0]<<" "<<dp[j][1]<<endl;
            // }
            for(int j = l; j<=r; j++) {
                if(j > 0) newdp[j][0] = dp[j-1][1]%mod;
                newdp[j][1] = (dp[r][0]-dp[j][0]+mod)%mod;
                //cout<<newdp[j][0]<<" "<<newdp[j][1]<<endl;
            }
            for(int j = l; j<=r; j++) {
                dp[j][0] = newdp[j][0];
                dp[j][1] = newdp[j][1];
            }
        }
        long long maxi = 0;
        for(int i = l; i<=r; i++) {
            maxi += dp[i][0]+dp[i][1];
            maxi %= mod;
        }
        return maxi;
    }
};