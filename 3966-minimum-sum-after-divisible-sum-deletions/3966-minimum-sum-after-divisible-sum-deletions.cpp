class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        long long ans = 0;
        vector<long long> dp(k,LLONG_MAX);
        dp[0] = 0;
        for(auto i: nums) {
            ans += i;
            dp[ans%k] = min(dp[ans%k],ans);
            ans = dp[ans%k];
        }
        return ans;
    }
};