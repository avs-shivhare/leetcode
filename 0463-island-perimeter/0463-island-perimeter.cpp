class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    void dfs(int row,int col,vector<vector<bool>> &vis,vector<vector<int>> &grid,long long &cnt,int &n,int &m) {
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            int newrow = row+rowdiff[i];
            int newcol = col+coldiff[i];
            if(newrow>=0 && newrow <n && newcol>=0 && newcol <m && grid[newrow][newcol] == 1) {
                if(!vis[newrow][newcol]) {
                    dfs(newrow,newcol,vis,grid,cnt,n,m);
                }
            }
            else cnt++;
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        long long cnt = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i,j,vis,grid,cnt,n,m);
                }
            }
        }
        return cnt;
    }
};