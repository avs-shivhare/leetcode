class Solution {
public:
    bool check(long long mid,vector<int> &arr,int n,long long extra) {
        long long sum = 0;
        for(auto i: arr) {
            sum += min(1ll*i,mid);
        }
        return sum >= mid*n;
    }
    long long maxRunTime(int n, vector<int>& bar) {
        long long l = 0,r = accumulate(bar.begin(),bar.end(),0ll);
        long long ans = 0;
        sort(bar.begin(),bar.end(),greater<int>());
        long long extra = accumulate(bar.begin()+n,bar.end(),0ll);
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(mid,bar,n,extra)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};