class Solution {
public:
    int rowdiff[4] = {1,-1,0,0};
    int coldiff[4] = {0,0,1,-1};
    bool flag = false;
    void dfs(int row,int col,vector<vector<int>> &grid1,vector<vector<int>> &grid2,vector<vector<bool>> &vis,int &n,int &m) {
        if(grid1[row][col] != grid2[row][col]) {
            flag = false;
        }
        vis[row][col] = true;
        for(int i =0; i<4; i++) {
            int newrow = row+rowdiff[i];
            int newcol = col+coldiff[i];
            if(newrow >=0 && newrow<n && newcol >=0 && newcol < m && !vis[newrow][newcol] && grid2[newrow][newcol]) {
                dfs(newrow,newcol,grid1,grid2,vis,n,m);
            }
        }
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int cnt =0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(!vis[i][j] && grid2[i][j]) {
                    flag = true;
                    dfs(i,j,grid1,grid2,vis,n,m);
                    if(flag) cnt++;
                }
            }
        }
        return cnt;
    }
};