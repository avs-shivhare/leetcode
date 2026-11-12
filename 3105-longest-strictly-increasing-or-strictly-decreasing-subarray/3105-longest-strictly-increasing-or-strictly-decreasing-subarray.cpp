class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0,r = 0;
        int ans = 0;
        while(r<n) {
            l = r;
            r++;
            while(r<n && nums[r-1] < nums[r]) r++;
            ans = max(ans,r-l);
        }
        l = 0,r = 0;
        while(r<n) {
            l = r;
            r++;
            while(r<n && nums[r-1] > nums[r]) r++;
            ans = max(ans,r-l);
        }
        return ans;
    }
};