class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        for(auto &i: nums) i %= 2;
        int ans = 0;
        vector<vector<int>> mpp(2,vector<int>(2,0));
        for(int i = 0; i<n; i++) {
            vector<vector<int>> dp(2,vector<int>(2,0));
            for(int j = 0; j<2; j++) {
                if(j) {
                    int rem = (nums[i]+1)%2;
                    dp[nums[i]][j] = mpp[rem][j]+1;
                }
                else {
                    dp[nums[i]][j] = mpp[nums[i]][j]+1;
                }
                //cout<<dp[nums[i]][j]<<" ";
                ans = max(dp[nums[i]][j],ans);
            }
            for(int j = 0; j<2; j++) mpp[nums[i]][j] = max(dp[nums[i]][j],mpp[nums[i]][j]);
        }
        return ans;
    }
};