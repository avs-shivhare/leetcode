class Solution {
public:
    int diffrow[4] = {-1,0,0,1};
    int diffcol[4]= {0,-1,1,0};
    void dfs(int row,int col,int &n,int &m,vector<vector<char>> &grid,vector<vector<bool>> &vis) {
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            int newRow = row+diffrow[i];
            int newCol = col+diffcol[i];
            if(newRow >= 0 && newRow <n && newCol>=0 && newCol <m && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                dfs(newRow,newCol,n,m,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int ans = 0;
        for(int i =0; i<n; i++) {
            for(int j =0; j<m;j++) {
                if(grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i,j,n,m,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};