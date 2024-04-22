class Solution {
public:
    int f(int ind,vector<int> &nums,vector<int> &dp,int &n) {
        if(ind == n-1) return true;
        if(ind >= n) return false;
        if(dp[ind] != -1) return dp[ind];
        for(int i =1; i<=nums[ind]; i++) {
            if(f(ind+i,nums,dp,n)) return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        //if(nums[0] == 0) return false;
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp,n); 
    }
};