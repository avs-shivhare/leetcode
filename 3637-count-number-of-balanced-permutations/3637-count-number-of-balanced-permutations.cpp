class Solution {
public:
    long long fact[81],infact[81];
    int fre[10];
    int mod = 1e9+7;
    long long dp[11][41][401];
    long long find(int i,int si,int sum,int &target,int &n) {
        if(i == 10) {
            if(si == n/2 && sum == target/2) {
                return (fact[si]*fact[n-si])%mod;
            }
            return 0;
        }
        if(dp[i][si][sum] != -1) return dp[i][si][sum];
        long long ans = 0;
        for(int j = 0; j<=min(n/2-si,fre[i]); j++) {
            ans += (((infact[j]*infact[fre[i]-j])%mod)*(find(i+1,si+j,sum+i*j,target,n)%mod))%mod;
            ans %= mod;
        }
        return dp[i][si][sum] = ans;
    }
    long long power(long long x,long long y) {
        if(y == 0) return 1;
        if(y == 1) return x;
        if(x == 0) return 0;
        long long ans = power(x,y/2);
        if(y&1) {
            return (((ans*ans)%mod)*x)%mod;
        }
        return (ans*ans)%mod;
    }
    void calFact() {
        fact[0] = 1;
        for(int i = 1; i<81; i++) {
            fact[i] = fact[i-1]*(long long)i;
            fact[i] %= mod;
        }
        infact[80] = power(fact[80],mod-2);
        for(int i = 79; i>=0; i--) {
            infact[i] = infact[i+1]*(long long)(i+1);
            infact[i] %= mod;
        }
    }

    int countBalancedPermutations(string num) {
        int sum = 0;
        int n = num.size();
        memset(fre,0,sizeof(fre));
        for(auto i: num) {
            fre[i-'0']++;
            sum += i-'0';
        }
        if(sum&1) return 0;
        calFact();
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,sum,n);
    }
};