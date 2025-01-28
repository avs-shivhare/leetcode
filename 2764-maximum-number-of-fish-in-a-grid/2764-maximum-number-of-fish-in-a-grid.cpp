class Solution {
public:
    int rowdiff[4] = {1,-1,0,0};
    int coldiff[4] = {0,0,-1,1};
    int temp = 0;
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m) {
        vis[r][c] = true;
        temp += grid[r][c];
        //temp = max(temp,curr);
        for(int i = 0; i<4; i++) {
            int newrow = r+rowdiff[i];
            int newcol = c+coldiff[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol] && grid[newrow][newcol]) {
                dfs(newrow,newcol,grid,vis,n,m);
            }
        }
        //vis[r][c] = false;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    temp = 0;
                    dfs(i,j,grid,vis,n,m);
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};