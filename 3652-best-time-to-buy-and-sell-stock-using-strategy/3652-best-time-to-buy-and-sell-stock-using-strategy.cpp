class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& st, int k) {
        long long ans = 0;
        int n = prices.size();
        for(int i = 0; i<n; i++) {
            ans += 1ll*st[i]*prices[i];
        }
        vector<long long> prefix(n+1,0);
        for(int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1]+prices[i-1];
        }
        long long psum = 0, ssum = ans;
        int l = 0,r = 0;
        while(r<n) {
            ssum -= 1ll*st[r]*prices[r];
            while(l<r && r-l+1 > k) {
                psum += 1ll*st[l]*prices[l];
                l++;
            }
            if(r-l+1 == k) {
                int mid = l+k/2;
                //cout<<l<<" "<<r<<" "<<mid<<" "<<ans<<" "<<prefix[r+1]-prefix[mid]<<" "<<psum<<" "<<ssum<<endl;
                ans = max(ans,prefix[r+1]-prefix[mid]+psum+ssum);
            }
            r++;
        }
        return ans;
    }
};