class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        vector<int> dp(n,1), cnt(n,1);
        for(int i =0; i<n;i++) {
            for(int j =0; j<i;j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[i] == dp[j]+1) {
                    cnt[i] += cnt[j];
                }
            }
            ans = max(ans,dp[i]);
        }
        int count=0;
        for(int i =0;i<n;i++) {
            if(ans == dp[i]) {
                count += cnt[i];
            }
        }
        return count;
    }
};