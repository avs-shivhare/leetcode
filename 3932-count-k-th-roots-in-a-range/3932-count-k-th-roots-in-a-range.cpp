class Solution {
public:
    long long power(long long a,long long b) {
        if(a == 0) return 0;
        if(b == 0) return 1;
        if(b == 1) return a;
        long long ans = power(a,b>>1ll);
        if(b&1ll) return ans*ans*a;
        return ans*ans;
    }
    int countKthRoots(int l, int r, int k) {
        if(k == 1) return 1ll*r-l+1;
        int cnt = 0;
        long long i = 0;
        long long p = 0;
        do {
            p = power(i,k);
            if(l <= p && p <= r) cnt++;
            i++;
        }while(p <= r);
        return cnt;
    }
};