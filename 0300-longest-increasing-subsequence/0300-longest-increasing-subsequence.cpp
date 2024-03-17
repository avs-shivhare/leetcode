class Solution {
public:
    //recursive method widh 2D dp
    // int f(int i,int j,vector<int> &nums,int &n,vector<vector<int>> &dp) {
    //     if(i == n) return 0;
    //     if(dp[i][j+1] != -1) return dp[i][j+1];
    //     int take =0;
    //     if(j == -1 || nums[i] > nums[j]) take = 1+f(i+1,i,nums,n,dp);
    //     take = max(take,f(i+1,j,nums,n,dp));
    //     return dp[i][j+1] = take;
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,nums,n,dp);
    // }

    //tabulation
    // int lengthOfLIS(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     for(int i = n-1; i>=0; i--) {
    //         for(int j = i-1; j>=-1; j--) {
    //             int take =0;
    //             if(j == -1 || nums[i] > nums[j]) take = 1+dp[i+1][i+1];
    //             take = max(take,dp[i+1][j+1]);
    //             dp[i][j+1] = take;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //space optimization 
    // int lengthOfLIS(vector<int>& nums) {
    //     int n= nums.size();
    //     vector<int> dp(n+1,0), next(n+1,0);
    //     for(int i = n-1; i>=0; i--) {
    //         for(int j = i-1; j>=-1; j--) {
    //             int take =0;
    //             if(j == -1 || nums[i] > nums[j]) take = 1+dp[i+1];
    //             take = max(take,dp[j+1]);
    //             next[j+1] = take;
    //         }
    //         dp = next;
    //     }
    //     return dp[0];
    // }

    //binary search 
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<n; i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
};