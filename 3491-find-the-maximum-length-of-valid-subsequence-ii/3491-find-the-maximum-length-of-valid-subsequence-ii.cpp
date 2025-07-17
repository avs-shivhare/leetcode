class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto &i: nums) i %= k;
        vector<vector<int>> dp(k,vector<int>(k,0));
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<k; j++) {
                int rem = (j-nums[i]+k)%k;
                dp[nums[i]][j] = max(dp[nums[i]][j],dp[rem][j]+1);
                ans = max(dp[nums[i]][j],ans);
            }
        }
        return ans;
    }
};