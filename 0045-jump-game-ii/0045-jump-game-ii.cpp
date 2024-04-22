class Solution {
public:
    int f(int i,vector<int> &num,int &n,vector<int> &dp) {
        if(i == n-1) {
            return 0;
        }
        if(i >= n) return 1e9;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        if(num[i] == 0) return 1e9;
        for(int ind =1; ind<=num[i]; ind++) {
            ans = min(ans,1+f(i+ind,num,n,dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }
};