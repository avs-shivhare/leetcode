class Solution {
public:
    int f(int row,int col,vector<vector<int>> &grid,vector<vector<int>> &dp,int &n,int &m) {
        if(row == n-1) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int mini = 1e9;
        for(int i = 0; i<m; i++) {
            if(col != i) {
                mini = min(mini,grid[row+1][i]+f(row+1,i,grid,dp,n,m));
            }
        }
        return dp[row][col] = mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int mini = 1e9;
        for(int i =0; i<m; i++) {
            mini = min(mini,grid[0][i]+f(0,i,grid,dp,n,m));
        }
        return mini;
    }
};