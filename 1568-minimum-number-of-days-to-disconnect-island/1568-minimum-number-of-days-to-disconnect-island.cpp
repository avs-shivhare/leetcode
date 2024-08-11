class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};
    bool flag = false;
    bool single = false;
    void dfs(int row,int col,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &n,int &m) {
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            flag = true;
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(0 <= newRow && newRow < n && 0 <= newCol && newCol < m && !vis[newRow][newCol] && grid[newRow][newCol]) {
                dfs(newRow,newCol,grid,vis,n,m);
            }
        }
        return;
    }
    bool check(vector<vector<int>> &grid) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(grid[i][j] && !vis[i][j]) {
                    dfs(i,j,grid,vis,n,m);
                    cnt++;
                }
                if(cnt == 2) return true;
            }
        }
        if(cnt == 0) return true;
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    if(flag) return 0;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(grid[i][j]) {
                    grid[i][j] = 0;
                    if(check(grid)) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        if(flag == false) return 0;
        return 2;
    }
};