class Solution {
public:
    int rowdiff[4] = {-1,0,0,1};
    int coldiff[4] = {0,-1,1,0};

    bool dfs(int row,int col,int prrow,int prcol,vector<vector<char>> &grid,vector<vector<bool>> &vis,vector<vector<bool>> &pathvis,int &n,int &m) {
        vis[row][col] = true;
        pathvis[row][col] = true;
        //cout<<row<<" "<<col<<endl;
        for(int i =0;i<4; i++) {
            int newRow = row+rowdiff[i];
            int newCol = col+coldiff[i];
            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m ) {
                if(grid[row][col] == grid[newRow][newCol]) {
                    if(!vis[newRow][newCol]) {
                        if(dfs(newRow,newCol,row,col,grid,vis,pathvis,n,m)) return true;
                    }
                    else if(prrow == newRow && prcol == newCol) continue;
                    else if(pathvis[newRow][newCol]) return true;
                }
            }
        }
        pathvis[row][col] = false;
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false)),pathvis(n,vector<bool>(m,false));
        for(int i =0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(!vis[i][j]) {
                    if(dfs(i,j,-1,-1,grid,vis,pathvis,n,m)) return true;
                }
            }
        }
        return false;
    }
};