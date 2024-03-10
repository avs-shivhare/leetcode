class Solution {
public:
    int f(int ind,int target,vector<int> &nums,vector<vector<int>> &dp) {
        if(ind == 0) {
            if(target == 0 && nums[ind] == 0) return 2;
            if(target == 0 || nums[ind] == target) return 1;
            return 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int nottake = f(ind-1,target,nums,dp);
        int take =0;
        if(nums[ind] <= target) take = f(ind-1,target-nums[ind],nums,dp);
        return dp[ind][target] = take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum-target <0 || (sum-target)%2 == 1) return 0;
        target = (sum-target)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(n-1,target,nums,dp);
    }
};