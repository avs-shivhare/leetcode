class Solution {
public:
    int mod = 1e9+7;
    long long fact[100001];
    long long inFact[100001];
    long long p(long long a,long long b) {
        if(a == 0) return 0;
        if(b == 1) return a;
        if(b == 0) return 1;
        long long ans = p(a,b>>1ll);
        if(b&1ll) return (((ans*ans)%mod)*a)%mod;
        return (ans*ans)%mod;
    }
    void find(int n) {
        fact[0] = 1;
        for(int i = 1; i<=n; i++) {
            fact[i] = fact[i-1]*i;
            fact[i] %= mod;
        }
        inFact[n] = p(fact[n],mod-2);
        for(int i = n-1; i>=0; i--) {
            inFact[i] = inFact[i+1]*(i+1);
            inFact[i] %= mod;
        }
    }
    int cal(int n,int k) {
        if(k>n) return 0;
        return (((fact[n]*inFact[n-k])%mod)*inFact[k])%mod;
    }
    int countVisiblePeople(int n, int pos, int k) {
        find(n);
        long long ans = 0;
        for(int i = 0; i<=k; i++) {
            long long l = cal(pos,i);
            long long r = cal(n-(pos+1),k-i);
            //cout<<l<<" "<<r<<" "<<i<<endl;
            ans = (ans+((l*r)%mod))%mod;
        }
        return (ans*2ll)%mod;
    }
};