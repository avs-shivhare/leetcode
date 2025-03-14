class Solution {
public:
    bool check(vector<int> &candies,long long &k,long long &mid) {
        long long cnt = 0;
        for(auto i: candies) {
            cnt += (long long)i/mid;
        }
        return cnt >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = 0;
        long long l = 1,r = *max_element(candies.begin(),candies.end());
        while(l<=r) {
            long long mid = (l+r)>>1;
            if(check(candies,k,mid)) {
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
};