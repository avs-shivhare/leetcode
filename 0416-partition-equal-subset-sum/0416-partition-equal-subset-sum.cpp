class Solution {
public:
    int dp[201][99001];
    int find(int i,int sum,vector<int> &nums) {
        if(sum < 0) return 0;
        if(i == nums.size()) {
            if(sum == 0) return 1;
            return 0;
        }
        if(dp[i][sum] != -1) return dp[i][sum];
        int take = 0,notTake = 0;
        take = find(i+1,sum-nums[i],nums);
        notTake = find(i+1,sum,nums);
        return dp[i][sum] = max(take,notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum & 1) return false;
        memset(dp,-1,sizeof(dp));
        int ans = find(0,sum/2,nums);
        if(ans > 0) return true;
        return false;
    }
};