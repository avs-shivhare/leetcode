class Solution {
public:
    long long dp[100001][2];
    long long find(int i,bool skip,vector<int> &nums) {
        if(i+1>= nums.size()) return 0;
        return dp[i][skip];
    }
    long long minIncrease(vector<int>& nums) {
        long long n = nums.size();
        if(n&1) {
            long sum = 0;
            for(int i = 1; i<n; i+=2) {
                sum += max({0ll,1ll*nums[i-1]-nums[i]+1,1ll*nums[i+1]-nums[i]+1});
            }
            return sum;
        }
        memset(dp,0,sizeof(dp));
        for(int i = n-2; i>=1; i--) {
            for(int skip = 0; skip<2; skip++) {
                long long take = max({0ll,1ll*nums[i-1]-nums[i]+1,1ll*nums[i+1]-nums[i]+1})+find(i+2,skip,nums);
                long long notTake = 1e18;
                if(!skip) notTake = find(i+1,true,nums);
                dp[i][skip] = min(take,notTake);
            }
        }
        return dp[1][false];
    }
};