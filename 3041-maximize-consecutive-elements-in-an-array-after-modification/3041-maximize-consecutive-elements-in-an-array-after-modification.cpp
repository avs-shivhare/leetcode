class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int> dp,dp2;
        int ans = 0;
        for(auto &i: nums) {
            dp2[i+1] = max({dp[i]+1,dp2[i]+1,dp2[i+1],dp[i-1]+1});
            dp2[i] = max({dp2[i],dp[i-2]+1,dp2[i-1]+1});
            dp[i] = max(dp[i],dp[i-1]+1);
            ans = max({ans,dp[i],dp2[i+1],dp2[i]});
        }
        return ans;
    }
};