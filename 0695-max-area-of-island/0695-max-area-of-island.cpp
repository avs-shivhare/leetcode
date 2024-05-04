class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    int dfs(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m,int &maxi) {
        vis[row][col] = true;
        int ans = 0;
        for(int i =0; i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow >=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && grid[newRow][newCol]) {
                ans += dfs(newRow,newCol,grid,vis,n,m,maxi);
            }
        }
        maxi = max(maxi,ans+1);
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxi = 0;
        int ans = 1;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    dfs(i,j,grid,vis,n,m,maxi);
                }
            }
        }
        return maxi;
    }
};