class Solution {
public:
    int dp[49001][3];
    int find(int i,int diff,vector<int> &arr) {
        if(diff < 0) return -1e9;
        if(i == arr.size()) {
            if(diff == 0) return 0;
            return -1e9;
        }
        if(dp[i][diff] != -1) return dp[i][diff];
        int take = -1e9,notTake = -1e9;
        take = arr[i]+find(i+1,(diff+arr[i])%3,arr);
        notTake = 0+find(i+1,diff,arr);
        return dp[i][diff] = max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,0,nums);
        if(ans <= 0) return 0;
        return ans;
    }
};