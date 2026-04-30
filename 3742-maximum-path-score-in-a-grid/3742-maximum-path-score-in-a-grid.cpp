class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(k+2,-1e9));
        for(int i = n-1; i>=0; i--) {
            vector<vector<int>> next(m+1,vector<int>(k+2,-1e9));
            for(int j = m-1; j>=0; j--) {
                for(int x = k; x>=0; x--) {
                    if(i == n-1 && j == m-1) {
                        int cost = 0;
                        if(grid[i][j]) cost = 1;
                        if(cost+x <= k) next[j][x] = grid[i][j];
                    }
                    else {
                        int ans = grid[i][j];
                        int cost = 0;
                        if(grid[i][j]) cost = 1;
                        if(cost+x <= k) next[j][x] = ans+max(dp[j][x+cost],next[j+1][x+cost]);
                    }
                }
            }
            dp = next;
        }
        int ans = INT_MIN;
        for(int i = 0; i<=k; i++) {
            ans = max(ans,dp[0][i]);
            cout<<dp[0][i]<<" ";
        }
        cout<<endl;
        if(ans < 0) return -1;
        return ans;
    }
};