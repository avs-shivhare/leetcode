class Solution {
public:
    int mod = 1e9+7;
    long long power(long long n,long long p) {
        if(p == 0) return 1;
        if(p == 1) return n;
        if(n == 0) return 0;
        long long ans = power(n,p/2);
        if(p&1) return (((ans*ans)%mod)*n)%mod;
        return (ans*ans)%mod;
    }
    int countGoodNumbers(long long n) {
        return (power(5,(n+1)/(long long)2)*power(4,n/(long long)2))%mod;
    }
};