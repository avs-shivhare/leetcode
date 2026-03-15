class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long last = 1000;
        for(long long i = 1000; i<=n+1; i = min(1ll*n+1,i*10ll)) {
            ans += i-last;
            last = i;
            if(i == n+1) break;
        }
        return ans;
    }
};