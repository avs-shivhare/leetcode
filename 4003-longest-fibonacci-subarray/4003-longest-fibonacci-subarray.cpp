class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        int ans = 2;
        for(int i = 2; i<n; i++) {
            if((long long)nums[i-2]+(long long)nums[i-1] == nums[i]) {
                dp[i] = dp[i-1]+1;
            }
            else dp[i] = 2;
            ans = max(ans,dp[i]);
        }
        //for(auto i: dp) cout<<i<<endl;
        return ans;
    }
};