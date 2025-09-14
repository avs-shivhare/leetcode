class Solution {
public:
    int dp[4001][4001];
    // int find(int i,int sum,vector<int> &nums,int &x) {
    //     if(sum < 0) return 0;
    //     if(i == nums.size()) {
    //         if(sum == 0) return 1;
    //         return 0;
    //     }
    //     if(dp[i][sum] != -1) return dp[i][sum];
    //     int ans = 0;
    //     ans = find(i+1,sum-(nums[i] > x? x: nums[i]),nums,x);
    //     if(ans) return dp[i][sum] = ans;
    //     ans = find(i+1,sum,nums,x);
    //     return dp[i][sum] = ans;
    // }
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> ans(n,false);
        vector<bool> dp(k+1,false);
        sort(nums.begin(),nums.end());
        dp[0] = 1;
        int j = 0;
        for(int i = 0; i<n; i++) {
            while(j<n && nums[j] < i+1) {
                for(int x = k; x>=nums[j]; x--) {
                    if(dp[x-nums[j]]) dp[x] = true;
                }
                j++;
            }
            for(int x = 0; x<=min(n-j,k/(i+1)); x++) {
                if(k-x*(i+1) >= 0 && dp[k-x*(i+1)]) {
                    ans[i] = true;
                    break;
                }
            }
        }
        return ans;
    }
};