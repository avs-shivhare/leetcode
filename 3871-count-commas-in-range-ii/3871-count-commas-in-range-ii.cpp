class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cnt = 3;
        for(long long i = 1000; i<=n; i *= 10ll) {
            ans += min(n-i+1,i*10ll-i)*(cnt/3);
            cnt++;
        }
        return ans;
    }
};