class Solution {
public:
    long long find(long long a,long long b,int &n) {
        int ans = 0;
        while(a<=n) {
            ans += min((long long)n+1,b)-a;
            a *= 10;
            b *= 10;
        }
        return ans;
    }
    int findKthNumber(int n, int k) {
        long long ans = 1;
        k--;
        while(k) {
            long long x = find(ans,ans+1,n);
            if(x <= k) {
                k -= x;
                ans++;
            }
            else {
                k--;
                ans *= 10;
            }
        }
        return ans;
    }
};