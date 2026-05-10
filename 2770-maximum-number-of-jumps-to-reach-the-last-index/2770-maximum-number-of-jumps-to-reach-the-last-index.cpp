class Solution {
public:
    int dp[1001];
    int find(int i,int &target,vector<int> &nums) {
        if(i >= nums.size()) return -1e9;
        if(i == nums.size()-1) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = -1e9;
        for(int j = i+1; j<nums.size(); j++) {
            if(-1ll*target <= 1ll*nums[j]-nums[i] && 1ll*nums[j]-nums[i] <= 1ll*target) {
                ans = max(ans,1+find(j,target,nums));
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,target,nums);
        if(ans < 0) return -1;
        return ans;
    }
};