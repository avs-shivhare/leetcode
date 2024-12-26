class Solution {
public:
    //int dp[21][11000];
    map<pair<int,int>,int> dp;
    int find(int i,vector<int> &nums,int &target,int sum) {
        if(i == nums.size()) {
            if(target == sum) return 1;
            return 0;
        }
        if(dp.count({i,sum})) return dp[{i,sum}];
        int ans = 0;
        ans += find(i+1,nums,target,sum+nums[i]);
        ans += find(i+1,nums,target,sum-nums[i]);
        return dp[{i,sum}] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        //memset(dp,-1,sizeof(dp));
        return find(0,nums,target,0);
    }
};