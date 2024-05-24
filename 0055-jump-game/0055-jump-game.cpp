class Solution {
public:
    // solve using dp 
    // int f(int ind,vector<int> &nums,vector<int> &dp,int &n) {
    //     if(ind == n-1) return true;
    //     if(ind >= n) return false;
    //     if(dp[ind] != -1) return dp[ind];
    //     for(int i =1; i<=nums[ind]; i++) {
    //         if(f(ind+i,nums,dp,n)) return dp[ind] = true;
    //     }
    //     return dp[ind] = false;
    // }
    // bool canJump(vector<int>& nums) {
    //     //if(nums[0] == 0) return false;
    //     int n = nums.size();
    //     vector<int> dp(n,-1);
    //     return f(0,nums,dp,n); 
    // }

    //greedy method 
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();
        for(int i =0; i<n; i++) {
            if(i> maxi) return false;
            maxi = max(maxi,i+nums[i]);
        } 
        return true;
    }
};