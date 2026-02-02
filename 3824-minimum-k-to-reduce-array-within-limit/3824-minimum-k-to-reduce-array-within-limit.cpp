class Solution {
public:
    bool check(vector<int> &nums,long long mid) {
        long long ans = 0;
        for(auto &i: nums) {
            ans += i/mid;
            if(i%mid != 0) ans++;
        }
        return ans <= 1ll*mid*mid;
    }
    int minimumK(vector<int>& nums) {
        long long l = 1,r = 1e5;
        long long ans = 0;
        while(l<=r) {
            long long mid = (l+r)>>1ll;
            if(check(nums,mid)) {
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};