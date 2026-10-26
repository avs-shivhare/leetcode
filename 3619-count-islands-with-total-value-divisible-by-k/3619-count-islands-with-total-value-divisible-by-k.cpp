class Solution {
public:
    int rowdiff[4] = {0,0,1,-1};
    int coldiff[4] = {1,-1,0,0};
    unordered_map<int,long long> mpp;
    void dfs(int r,int c,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m,int &rank) {
        vis[r][c] = true;
        mpp[rank] += grid[r][c];
        for(int i = 0; i<4; i++) {
            int nr = r+rowdiff[i];
            int nc = c+coldiff[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] && !vis[nr][nc]) {
                dfs(nr,nc,grid,vis,n,m,rank);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    cnt++;
                    dfs(i,j,grid,vis,n,m,cnt);
                    if(mpp[cnt]%k == 0) ans++;
                }
            }
        }
        return ans;
    }
};