class Solution {
public:
    long long dp[100001][2][2];
    long long find(int i,int even,int take,vector<int> &nums) {
        if(i >= nums.size()) {
            if(even) return -1e18;
            return 1e18;
        }
        if(dp[i][even][take] != -1) return dp[i][even][take];
        long long ans = 0;
        if(even) {
            ans = max({1ll*nums[i],1ll*nums[i]-find(i+1,!even,take,nums)});
            if(!take) ans = max(ans,find(i+1,even,1,nums));
        }
        else {
            ans = min({1ll*nums[i],1ll*nums[i]-find(i+1,!even,take,nums)});
            if(!take) ans = min(ans,find(i+1,even,1,nums));
        }
        //cout<<i<<" "<<even<<" "<<ans<<endl;
        return dp[i][even][take] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        //if(nums.size() == 1) return nums[0];
        int n = nums.size();
        long long ans = -1e18;
        for(int i = n-1; i>=0; i--) {
            ans = max(ans,find(i,1,0,nums));
        }
        return ans;
    }
};