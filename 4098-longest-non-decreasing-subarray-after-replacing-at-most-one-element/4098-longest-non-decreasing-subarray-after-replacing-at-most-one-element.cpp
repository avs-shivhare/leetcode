class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,1),suffix(n,1);
        int ans = 1;
        for(int i = 1; i<n; i++) {
            if(nums[i-1] <= nums[i]) prefix[i] += prefix[i-1];
            ans = max(ans,prefix[i]);
        }
        for(int i = n-2; i>=0; i--) {
            if(nums[i] <= nums[i+1]) suffix[i] += suffix[i+1];
            ans = max(ans,suffix[i]);
        }
        for(int i = 1; i<n-1; i++) {
            if(nums[i-1] <= nums[i+1]) ans = max(ans,prefix[i-1]+suffix[i+1]+1);
            else ans = max({ans,prefix[i-1]+1,suffix[i+1]+1});
        }
        for(int i = 0; i<n-1; i++) {
            ans = max(ans,prefix[i]+1);
        }
        for(int i = n-1; i>0; i--) {
            ans = max(ans,suffix[i]+1);
        }
        return ans;
    }
};