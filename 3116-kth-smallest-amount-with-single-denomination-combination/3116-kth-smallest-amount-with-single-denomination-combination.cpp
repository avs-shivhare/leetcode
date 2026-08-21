class Solution {
public:
    long long hcf(long long a,long long b) {
        if(a == 0) return b;
        if(b == 0) return a;
        if(a > b) return hcf(a%b,b);
        return hcf(a,b%a);
    }
    long long lcm(long long a,long long b) {
        return a*b/hcf(a,b);
    }
    bool check(vector<int> &coins,long long &mid,int &k) {
        long long cnt = 0;
        int n = coins.size();
        for(int i = 1; i<(1<<n); i++) {
            long long l = 1;
            int bit = 0;
            for(int j = 0; j<n; j++) {
                if(i&(1<<j)) {
                    bit++;
                    long long g = hcf(l,coins[j]);
                    l = (l*coins[j])/g;
                }
                if(l > mid) break;
            }
            if(bit&1) cnt += mid/l;
            else cnt -= mid/l;
        }
        return cnt >= k;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        vector<long long> temp;
        int n = coins.size();
        sort(coins.begin(),coins.end());
        long long ans = -1;
        long long l = 1, r = 1e18;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(coins,mid,k)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};