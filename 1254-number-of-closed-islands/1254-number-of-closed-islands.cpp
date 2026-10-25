class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    bool dfs(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis,int &n,int &m) {
        vis[r][c] = 1;
        bool ans = true;
        for(int i = 0; i<4; i++) {
            int nr = r+rowdiff[i];
            int nc = c+coldiff[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                if(!vis[nr][nc] && grid[nr][nc] == 0) {
                    bool flag = dfs(nr,nc,grid,vis,n,m);
                    ans = ans && flag;
                }
            }
            else ans = false;
        }
        return ans;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 0) {
                    cnt += dfs(i,j,grid,vis,n,m);
                    // cout<<i<<" "<<j<<" "<<flag<<endl;
                    // cnt += flag;
                }
            }
        }
        return cnt;
    }
};