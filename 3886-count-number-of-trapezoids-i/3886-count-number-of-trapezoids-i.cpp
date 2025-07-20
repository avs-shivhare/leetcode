class Solution {
public:
    int mod = 1e9+7;
    long long fact[100001];
    long long inFact[100001];
    long long power(long long x,long long y) {
        if(x == 0) return 0;
        if(y == 0) return 1;
        if(y == 1) return x;
        long long ans = power(x,y/2);
        if(y&1) {
            return (((ans*ans)%mod)*x)%mod;
        }
        return (ans*ans)%mod;
    }
    void factorial() {
        fact[0] = 1;
        for(int i = 1; i<=1e5; i++) {
            fact[i] = fact[i-1]*1ll*i;
            fact[i] %= mod;
        }
       // cout<<fact[100000]<<endl;
        inFact[100000] = power(fact[100000],mod-2);
        for(int i = 1e5-1; i>=0; i--) {
            inFact[i] = inFact[i+1]*1ll*(i+1);
            inFact[i] %= mod;
        }
        return;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        factorial();
        unordered_map<long long,long long> mpp;
        long long ans = 0;
        for(auto i: points) {
            mpp[i[1]]++;
        }
        vector<long long> x;
        for(auto i: mpp) {
            if(i.second > 1) {
                //cout<<i.second<<" "<<fact[i.second]<<" "<<inFact[i.second]<<endl;
                if(x.empty()) x.push_back(((fact[i.second]*inFact[2])%mod*inFact[i.second-2])%mod);
                else x.push_back(((fact[i.second]*inFact[2])%mod*inFact[i.second-2])%mod+x.back());
            }
        }
        int n = x.size();
        //for(auto i: x) cout<<i<<endl;
        for(int i =0; i<n-1; i++) {
            //cout<<x[i]<<endl;
            long long t = x[i];
            if(i > 0) t -= x[i-1];
            long long tt = x[n-1]-x[i];
            ans += (t*tt)%mod;
            ans %= mod;
        }
        return ans;
    }
};