class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cnt = 2;
        long long last = 1000;
        for(long long i = 1000; i<=n+1; i = min(n+1,i*10ll)) {
            ans += (i-last)*(cnt/3ll);
            last = i;
            cnt++;
            if(i == n+1) break;
        }
        return ans;
    }
};