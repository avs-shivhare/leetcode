class Solution {
public:
    int numOfWays(int n) {
        long long x = 6,y = 6;
        long long mod = 1e9+7;
        for(int i = 2; i<=n; i++) {
            long long xx = (3*x+2*y)%mod;
            long long yy = (2*x+2*y)%mod;
            x = xx;
            y = yy;
        }
        return (x+y)%mod;
    }
};