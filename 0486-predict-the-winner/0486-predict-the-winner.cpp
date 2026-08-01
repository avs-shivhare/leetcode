class Solution {
public:
    int dp[21][21][2];
    int find(int l,int r,int turn,vector<int> &nums) {
        if(l > r) return 0;
        if(dp[l][r][turn] != -1) return dp[l][r][turn];
        int left = 0,right = 0;
        if(turn) {
            left = find(l+1,r,!turn,nums)-nums[l];
            right = find(l,r-1,!turn,nums)-nums[r];
        }
        else {
            left = find(l+1,r,!turn,nums)+nums[l];
            right = find(l,r-1,!turn,nums)+nums[r];
        }
        if(turn) return dp[l][r][turn] = min(left,right);
        return dp[l][r][turn] = max(left,right);
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(0,nums.size()-1,0,nums) >= 0;
    }
};