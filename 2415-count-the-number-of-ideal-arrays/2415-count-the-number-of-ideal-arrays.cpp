class Solution {
public:
    int mod = 1e9+7;
    void find(int n,unordered_map<int,int> &mpp,vector<int> &sprime) {
        while(n > 1) {
            int x = sprime[n];
            //cout<<x<<" "<<n<<endl;
            mpp[x]++;
            n /= x;
        }
        return;
    }
    long long power(long long a,long long b) {
        if(a == 0) return 0;
        if(b == 0) return 1;
        if(b == 1) return a;
        long long ans = power(a,b/2);
        if(b & 1) {
            return (a*((ans*ans)%mod))%mod;
        }
        return (ans*ans)%mod;
    }
    long long com(int a,int b,long long fact[],long long infact[]) {
        if(b > a) return 0;
        return (fact[a]*infact[b]%mod*infact[a-b])%mod;
    }
    int idealArrays(int n, int m) {
        long long fact[100001];
        long long infact[100001];
        fact[0] = 1;
        for(int i = 1; i<1e5+1; i++) {
            fact[i] = (long long)i*fact[i-1];
            fact[i] %= mod;
        }
        infact[(int)1e5] = power(fact[(int)1e5],mod-2);
        for(int i = 1e5-1; i>=0; i--) {
            infact[i] = infact[i+1]*(long long)(i+1);
            infact[i] %= mod;
        }
        vector<int> sprime(m+1,0);
        for(int i = 2; i*i<=m; i++) {
            if(sprime[i] == 0) {
                for(int j = i; j<=m; j+=i) {
                    if(sprime[j] == 0) sprime[j] = i;
                }
            }
        }
        for(int i = 0; i<=m; i++) {
            if(sprime[i] == 0) sprime[i] = i;
        }
        long long ans = 0;
        for(int i = 1; i<=m; i++) {
            unordered_map<int,int> mpp;
            find(i,mpp,sprime);
            long long temp = 1;
            for(auto j: mpp) {
                temp = temp*com(n+j.second-1,j.second,fact,infact);
                temp %= mod;
            }
            ans += temp;
            ans %= mod;
        }
        return ans;
    }
};