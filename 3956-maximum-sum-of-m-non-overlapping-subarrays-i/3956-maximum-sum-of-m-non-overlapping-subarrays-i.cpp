class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1e18));
        vector<long long> prefix(n+1,0);
        for(int i = 1; i<=n; i++) prefix[i] = prefix[i-1]+nums[i-1];
        for(int i = 0; i<=n; i++) {
            dp[0][i] = 0;
        }
        long long ans = -1e18;
        for(int i = 1; i<=m; i++) {
            dp[i][n] = 0;
            deque<int> dq;
            for(int j = n-1; j>=0; j--) {
                if(j+l <= n) {
                    long long curr = prefix[j+l]+dp[i-1][j+l];
                    while(!dq.empty()) {
                        int ind = dq.back();
                        long long val = prefix[ind]+dp[i-1][ind];
                        if(val >= curr) break;
                        dq.pop_back();
                    }
                    dq.push_back(j+l);
                }
                while(!dq.empty() && dq.front() > j+r) dq.pop_front();
                dp[i][j] = dp[i][j+1];
                if(!dq.empty()) {
                    int k = dq.front();
                    dp[i][j] = max(dp[i][j],dp[i-1][k]+prefix[k]-prefix[j]);
                }
            }
            ans = max(dp[i][0],ans);
        }
        if(ans == 0) {
            long long x = LLONG_MIN;
            for(int i = 0; i<n; i++) {
                for(int len = l; len<=r && i+len<=n; len++) {
                    x = max(x,prefix[i+len]-prefix[i]);
                }
            }
            return x;
        }
        return ans;
    }
};