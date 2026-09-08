class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        for(int i = 1000; i<=n; i*=10) {
            int maxi = min(n-i+1,i*10-i);
            ans += maxi;
        }
        return ans;
    }
};