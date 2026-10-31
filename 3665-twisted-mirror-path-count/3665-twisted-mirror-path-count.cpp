class Solution {
public:
    int mod = 1e9+7;
    int dp[501][501][2];
    int find(int r,int c,int dir,vector<vector<int>> &grid) {
        if(r >= grid.size() || c >= grid[0].size()) return 0;
        if(r == grid.size()-1 && c == grid[0].size()-1) return 1;
        if(dp[r][c][dir] != -1) return dp[r][c][dir];
        if(grid[r][c] == 1) {
            if(dir) return find(r+1,c,0,grid);
            else return find(r,c+1,1,grid);
        }
        int ans = find(r+1,c,0,grid)%mod;
        ans = (ans+find(r,c+1,1,grid))%mod;
        return dp[r][c][dir] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,grid);
    }
};