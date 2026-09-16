int mod = 1e9+7;
int dp[1001][1001][2];
class Solution {
public:
    int find(int i,int k,int can,int &n) {
        //cout<<i<<" "<<k<<endl;
        if(k < 0) return 0;
        if(i >= n) {
            if(k == 0 && can == false) return 1;
            return 0;
        }
        if(dp[i][k][can] != -1) return dp[i][k][can];
        int ans = 0;
        if(!can) {
            ans = (ans+find(i+1,k,can,n))%mod;
            ans = (ans+find(i+1,k,true,n))%mod;
        }
        else {
            ans = (ans+find(i,k-1,false,n))%mod;
            ans = (ans+find(i+1,k,can,n))%mod;
        }
        //cout<<i<<" "<<k<<" "<<ans<<endl;
        return dp[i][k][can] = ans;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,k,false,n);
    }
};