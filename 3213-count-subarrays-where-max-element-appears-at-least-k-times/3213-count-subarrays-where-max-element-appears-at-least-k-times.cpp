class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi = 0;
        for(auto i: nums) {
            maxi = max(maxi,i);
        }
        int n = nums.size();
        int l = 0,r = 0;
        long long ans = 0;
        int cnt = 0;
        while(r<n) {
            if(nums[r] == maxi) cnt++;
            while(l<=r && cnt >= k) {
                ans += n-r;
                if(nums[l] == maxi) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};