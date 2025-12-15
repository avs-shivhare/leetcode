class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        int l = 0,r = 0;
        while(r<n) {
            r = l+1;
            ans++;
            while(r<n && prices[r]+1 == prices[r-1]) {
                ans += r-l+1;
                // cout<<l<<" "<<r<<" "<<ans<<endl;
                r++;
            }
            l = r;
        }
        return ans;
    }
};