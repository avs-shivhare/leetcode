class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(int r,int c,int x,vector<vector<int>> &grid) {
        //cout<<r<<" "<<c<<" "<<x<<endl;
        if(r == grid.size()-1 && c == grid[0].size()-1) return grid[r][c]^x;
        if(r >= grid.size() || c >= grid[0].size()) return 1e9;
        if(dp[r][c][x] != -1) return dp[r][c][x];
        int ans = 1e9;
        ans = min({ans,find(r+1,c,x^grid[r][c],grid),find(r,c+1,x^grid[r][c],grid)});
        return dp[r][c][x] = ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(9999,-1)));
        return find(0,0,0,grid);
    }
};