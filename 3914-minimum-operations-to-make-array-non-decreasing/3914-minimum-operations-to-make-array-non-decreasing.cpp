class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i = 1; i<n; i++) {
            if(nums[i-1]+ans > nums[i]+ans) {
                ans += (1ll*ans+nums[i-1])-(1ll*ans+nums[i]);
            }
        }
        return ans;
    }
};