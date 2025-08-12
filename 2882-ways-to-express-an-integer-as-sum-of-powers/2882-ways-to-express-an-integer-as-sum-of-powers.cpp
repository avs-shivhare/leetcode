class Solution {
public:
    int mod = 1e9+7;
    int dp[301][301];
    long long power(long long x,long long n) {
        if(x == 0) return 0;
        if(n == 1) return x;
        if(n == 0) return 1;
        long long ans = power(x,n/2);
        if(n&1) return (((ans*ans)%mod)*x)%mod;;
        return (ans*ans)%mod;
    }
    int find(int i,int sum,int &x) {
        if(sum < 0) return 0;
        if(sum == 0) return 1;
        if(i >= 301) return 0;
        //cout<<sum<<" "<<i<<endl;
        if(dp[sum][i] != -1) return dp[sum][i];
        long long ans = find(i+1,sum-power(i,x),x);
        ans += find(i+1,sum,x);
        ans %= mod;
        return dp[sum][i] = ans;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return find(1,n,x);
    }
};