class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(m == 1) return 0;
        vector<vector<long long>> prefix(m,vector<long long>(n+1,0));
        for(int j = 0; j<m; j++) {
            for(int i = 0; i<n; i++) {
                prefix[j][i+1] = prefix[j][i]+grid[i][j];
            }
        }
        vector<vector<long long>> dp(n+1,vector<long long>(n+1,0)), preMax(n+1,vector<long long>(n+1,0)), sufMax(n+1,vector<long long>(n+1,0));
        for(int col = 1; col<m; col++) {
            vector<vector<long long>> next(n+1,vector<long long>(n+1,0));
            for(int curr = 0; curr<=n; curr++) {
                for(int prev = 0; prev<=n; prev++) {
                    if(curr <= prev) {
                        long long gain = prefix[col][prev]-prefix[col][curr];
                        next[curr][prev] = max(next[curr][prev],sufMax[prev][0]+gain);
                    }
                    else {
                        long long gain = prefix[col-1][curr]-prefix[col-1][prev];
                        next[curr][prev] = max({next[curr][prev],sufMax[prev][curr],preMax[prev][curr]+gain});
                    }
                }
            }
            for(int curr = 0; curr<=n; curr++) {
                preMax[curr][0] = next[curr][0];
                for(int prev = 1; prev<=n; prev++) {
                    long long penalty = 0;
                    if(prev > curr) {
                        penalty = prefix[col][prev]-prefix[col][curr];
                    }
                    preMax[curr][prev] = max(preMax[curr][prev-1],next[curr][prev]-penalty);
                }
                sufMax[curr][n] = next[curr][n];
                for(int prev = n-1; prev>=0; prev--) {
                    sufMax[curr][prev] = max(sufMax[curr][prev+1],next[curr][prev]);
                }
            }
            dp = next;
        }
        long long ans = 0;
        for(int k = 0; k<=n; k++) {
            ans = max({ans,dp[0][k],dp[n][k]});
        }
        return ans;
    }
};