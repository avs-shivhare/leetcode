class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(int r,int c,int x,vector<vector<int>> &grid) {
        if(r == grid.size()-1 && c == grid[0].size()-1) {
            return x^grid[r][c];
        }
        if(dp[r][c][x] != -1) return dp[r][c][x];
        int ans = INT_MAX;
        if(c+1 < grid[0].size()) ans = min(ans,find(r,c+1,grid[r][c]^x,grid));
        if(r+1 < grid.size()) ans = min(ans,find(r+1,c,grid[r][c]^x,grid));
        return dp[r][c][x] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(9999,-1)));
        return find(0,0,0,grid);
    }
};