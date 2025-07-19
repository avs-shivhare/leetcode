class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    long long sum = 0;
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m) {
        vis[r][c] = true;
        sum += grid[r][c];
        for(int i = 0; i<4; i++) {
            int newr = r+rowdiff[i];
            int newc = c+coldiff[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && !vis[newr][newc] && grid[newr][newc]) {
                dfs(newr,newc,grid,vis,n,m);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    sum = 0;
                    dfs(i,j,grid,vis,n,m);
                    cnt += (sum%k == 0);
                }
            }
        }
        return cnt;
    }
};