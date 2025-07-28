class Solution {
public:
    int dp[999999][20];
    int find(int i,int x,vector<int> &nums,int &sum) {
        if(i == nums.size()) {
            return x == sum;
        }
        if(dp[x][i] != -1) return dp[x][i];
        int ans = 0;
        ans = find(i+1,x|nums[i],nums,sum);
        ans += find(i+1,x,nums,sum);
        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(auto i: nums) x |= i;
        memset(dp,-1,sizeof(dp));
        return find(0,0,nums,x);
    }
};