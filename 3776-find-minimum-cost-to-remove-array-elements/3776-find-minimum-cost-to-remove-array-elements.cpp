class Solution {
public:
    int dp[1001][1001];
    int find(int i,int left,vector<int> &nums) {
        if(i == nums.size()) return nums[left];
        if(i == nums.size()-1) return max(nums[left],nums[i]);
        if(dp[i][left] != -1) return dp[i][left];
        int first = max(nums[i],nums[left])+find(i+2,i+1,nums);
        int second = max(nums[i],nums[i+1])+find(i+2,left,nums);
        int second2 = max(nums[left],nums[i+1])+find(i+2,i,nums);
        return dp[i][left] = min({first,second,second2});
    }
    int minCost(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(1,0,nums);
    }
};