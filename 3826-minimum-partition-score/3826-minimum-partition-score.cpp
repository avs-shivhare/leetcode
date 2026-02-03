class Solution {
public:
    vector<long long> prefix;
    long long dp[1001][1001];
    long long cal(int l,int r) {
        long long sum = prefix[r+1]-prefix[l];
        return (sum*(sum+1ll))>>1ll;
    }
    long long find(int i,int k,vector<int> &nums) {
        if(i >= nums.size() && k <= 0) return 0;
        if(i >= nums.size() || k <= 0) return 1e18;
        if(dp[i][k] != -1) return dp[i][k];
        long long ans = 1e18;
        for(int j = i; j<=nums.size()-k; j++) {
            long long cost = cal(i,j);
            if(cost >= ans) break;
            ans = min(ans,cost+find(j+1,k-1,nums));
        }
        return dp[i][k] = ans;
    }
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        prefix.resize(n+1);
        for(int i = 1; i<=n; i++) {
            prefix[i] = prefix[i-1]+nums[i-1];
        }
        memset(dp,-1,sizeof(dp));
        return find(0,k,nums);
    }
};