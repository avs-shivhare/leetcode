class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int tt = r-l+1;
        int mod = 1e9+7;
        if(n == 1) return tt;
        vector<long long> prefix(tt+1,0),suffix(tt+1,0);
        for(int i = 1; i<=tt; i++) {
            prefix[i] = i-1;
            suffix[i] = tt-i;
        }
        vector<long long> up(tt+1,0),down(tt+1,0),nextU(tt+1,0),nextD(tt+1,0);
        for(int x = 3; x<=n; x++) {
            for(int j = 1; j<=tt; j++) {
                up[j] = (up[j-1]+prefix[j])%mod;
                down[j] = (down[j-1]+suffix[j])%mod;
            }
            for(int j = 1; j<=tt; j++) {
                nextU[j] = down[j-1];
                nextD[j] = (up[tt]-up[j]+mod)%mod;
            }
            prefix = nextU;
            suffix = nextD;
        }
        long long ans = 0;
        for(int i = 1; i<=tt; i++) {
            ans = (ans+prefix[i]+suffix[i])%mod;
        }
        return ans;
    }
};