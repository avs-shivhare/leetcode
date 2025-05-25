class Solution {
public:
    long long minCuttingCost(int _n, int _m, int _k) {
        if(_m > _k) return minCuttingCost(_m,_n,_k);
        if(_n <= _k && _m <= _k) return 0;
        long long ans = 1e18, n = _n, m = _m,k = _k;
        for(long long i = 1; i<=k; i++) {
            long long l = i,r = n-i;
            if(l <= k && r <= k) ans = min(ans,l*r);
        }
        return ans;
    }
};