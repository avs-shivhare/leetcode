class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,LLONG_MIN)),dp2(n,vector<long long>(m,LLONG_MAX));
        int mod = 1e9+7;
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                // if(grid[i][j] == 0) {
                //     cnt++;
                //     dp[i][j] = 0;
                //     dp2[i][j] = 0;
                //     continue;
                // }
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                    dp2[i][j] = grid[i][j];
                }
                else {
                    if(i-1 >= 0) {
                        dp[i][j] = max({dp[i][j],dp2[i-1][j]*grid[i][j],dp[i-1][j]*grid[i][j]});
                        dp2[i][j] = min({dp2[i][j],dp2[i-1][j]*grid[i][j],dp[i-1][j]*grid[i][j]});
                    }
                    if(j-1 >= 0) {
                        dp[i][j] = max({dp[i][j],dp2[i][j-1]*grid[i][j],dp[i][j-1]*grid[i][j]});
                        dp2[i][j] = min({dp2[i][j],dp2[i][j-1]*grid[i][j],dp[i][j-1]*grid[i][j]});
                    }
                }
            }
        }
        //cout<<dp[n-1][m-1]<<endl;
        if(dp[n-1][m-1] < 0 && dp2[n-1][m-1] < 0) {
            return -1;
        }
        return max(dp[n-1][m-1]%mod,dp2[n-1][m-1]%mod);
    }
};