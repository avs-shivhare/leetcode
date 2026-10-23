class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = INT_MAX;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            if(nums[i] != i) {
                ans &= nums[i]&i;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};