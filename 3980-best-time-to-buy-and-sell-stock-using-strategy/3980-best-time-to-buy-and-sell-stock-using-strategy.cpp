class Solution {
public:
    long long get(vector<long long> &prefix,int l,int r) {
        if(r >= prefix.size() || l >= prefix.size()) return 0;
        long long sum = prefix[r];
        if(l > 0) sum -= prefix[l-1];
        return sum;
    }
    long long maxProfit(vector<int>& prices, vector<int>& st, int k) {
        int n = prices.size();
        vector<long long> prefix(n,0),prefix2(n,0);
        prefix[0] = (long long)prices[0]*st[0];
        prefix2[0] = prices[0];
        for(int i =1; i<n; i++) {
            prefix[i] = prefix[i-1]+st[i]*(long long)prices[i];
            prefix2[i] = prefix2[i-1]+prices[i];
        }
        // for(auto i: prefix) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: prefix2) cout<<i<<" ";
        // cout<<endl;
        long long ans = prefix[n-1];
        int l = 0,r = 0;
        while(r<n) {
            while(l<r && r-l+1 > k) {
                l++;
            }
            if(r-l+1 == k) {
                int mid = (r+l)>>1;
                long long sum = 0;
                if(l > 0) sum = prefix[l-1];
                //cout<<sum<<endl;
                sum += get(prefix,r+1,n-1);
                //cout<<sum<<endl;
                long long temp = prefix2[r]-prefix2[mid];
                sum += temp;
                //cout<<sum<<endl;
                ans = max(ans,sum);
                //cout<<l<<" "<<r<<" "<<mid<<" "<<sum<<endl;
            }
            r++;
        }
        return ans;
    }
};