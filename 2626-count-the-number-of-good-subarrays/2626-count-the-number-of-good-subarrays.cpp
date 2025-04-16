class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans = 0;
        int l = 0,r = 0;
        int n = nums.size();
        unordered_map<int,int> mpp;
        int cnt = 0;
        while(r<n) {
            cnt += mpp[nums[r]];
            mpp[nums[r]]++;
            while(l<r && cnt >= k) {
                ans += n-r;
                mpp[nums[l]]--;
                cnt -= mpp[nums[l]];
                l++;
            }
            r++;
        }
        return ans;
    }
};