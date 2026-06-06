class Solution {
public:
    long long dp[100001][2];
    long long find(int i,int prev,vector<int> &nums,string &s) {
        if(i >= s.size()) return 0;
        if(dp[i][prev] != -1) return dp[i][prev];
        long long take = 0,notTake = 0;
        if(!prev && s[i] == '1') {
            take = 1ll*nums[i]+find(i+1,0,nums,s);
        } 
        else if(i+1 < s.size() && s[i+1] == '1') {
            take = 1ll*nums[i]+find(i+1,1,nums,s);
        }
        notTake = 0+find(i+1,0,nums,s);
        return dp[i][prev] = max(take,notTake);
    }
    long long maxTotal(vector<int>& nums, string s) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,nums,s);
    }
};