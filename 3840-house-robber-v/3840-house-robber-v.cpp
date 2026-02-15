class Solution {
public:
    long long dp[100001];
    long long find(int i,int &n) {
        if(i>= n) return 0;
        return dp[i];
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i = n-1; i>=0; i--) {
            long long take = 0,notTake = 0;
            if(i+1<n) {
                if(colors[i] == colors[i+1]) take = nums[i]+find(i+2,n);
                else take = nums[i]+find(i+1,n);
            }
            else {
                take = nums[i]+find(i+1,n);
            }
            notTake = find(i+1,n);
            dp[i] = max(take,notTake);
        }
        return dp[0];
    }
};