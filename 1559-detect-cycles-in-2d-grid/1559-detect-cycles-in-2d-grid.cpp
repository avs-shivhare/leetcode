class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    bool dfs(int r,int c,vector<vector<char>> &grid,vector<vector<int>> &vis,vector<vector<int>> &path,int &n,int &m,int cnt) {
        vis[r][c] = 1;
        path[r][c] = cnt;
        for(int i = 0; i<4; i++) {
            int nr = r+rowdiff[i];
            int nc = c+coldiff[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == grid[r][c]) {
                if(vis[nr][nc] && path[nr][nc] && cnt-path[nr][nc]+1 >= 4) return true;
                else if(!vis[nr][nc] && dfs(nr,nc,grid,vis,path,n,m,cnt+1)) {
                    return true;
                }
            }
        }
        path[r][c] = 0;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0)), path(n,vector<int>(m,0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && dfs(i,j,grid,vis,path,n,m,1)) return true; 
            }
        }
        return false;
    }
};