class Solution {
public:
    int dp[99001][41];
    int find(int i,int x,vector<int> &nums,int &target) {
        if(i == nums.size()) {
            if(x == target) return 0;
            return 1e9;
        }
        if(dp[x][i] != -1) return dp[x][i];
        int take = 0+find(i+1,nums[i]^x,nums,target);
        int notTake = 1+find(i+1,x,nums,target);
        return dp[x][i] = min(take,notTake);
    }
    int minRemovals(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,0,nums,target);
        if(ans >= 1e9) return -1;
        return ans;
    }
};