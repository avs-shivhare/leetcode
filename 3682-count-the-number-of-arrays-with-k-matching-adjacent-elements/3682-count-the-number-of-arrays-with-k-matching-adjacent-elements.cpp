class Solution {
public:
    int mod = 1e9+7;
    vector<long long> fact,inFact;
    long long power(long long x,long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 0) return x;
        long long ans = power(x,n/2);
        if(n&1) {
            return (((ans*ans)%mod)*x)%mod;
        }
        return (ans*ans)%mod;
    }
    long long nCr(long long n,long long r) {
        if(r > n) return 0;
        return (((fact[n]*inFact[r])%mod)*inFact[n-r])%mod;
    }
    int countGoodArrays(int n, int m, int k) {
        fact.resize(1e5+1,0);
        inFact.resize(1e5+1,0);
        fact[0] = 1;
        for(long long i = 1; i<=1e5; i++) {
            fact[i] = fact[i-1]*i;
            fact[i] %= mod;
        }
        inFact[1e5] = power(fact[1e5],mod-2);
        for(int i = 1e5-1; i>=0; i--) {
            inFact[i] = (inFact[i+1]*(i+1))%mod;
        }
        long long ans = (long long)m*power(m-1,n-(k+1))%mod;
        ans = ans*nCr(n-1,k)%mod;
        return ans;
    }
};