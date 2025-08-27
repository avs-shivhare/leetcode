class Solution {
public:
    int dp[501][501][4][2];
    int row[4] = {-1,-1,1,1};
    int col[4] = {-1,1,1,-1};
    int find(int r,int c,int dir,int cnt,vector<vector<int>> &grid,int &n,int &m) {
        if(dp[r][c][dir][cnt] != -1) return dp[r][c][dir][cnt];
        int ans = 1;
        int newr = r+row[dir];
        int newc = c+col[dir];
        if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] != 1 && grid[newr][newc] != grid[r][c]) {
            ans = max(ans,1+find(newr,newc,dir,cnt,grid,n,m));
        }
        if(cnt < 1) {
            int ndir = (dir+1)%4;
            newr = r+row[ndir];
            newc = c+col[ndir];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] != 1 && grid[newr][newc] != grid[r][c]) {
                ans = max(ans,1+find(newr,newc,ndir,cnt+1,grid,n,m));
            }
        }
        return dp[r][c][dir][cnt] = ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] ==1) {
                    ans = max(ans,1);
                    for(int x = 0; x<4; x++) {
                        int newr = i+row[x];
                        int newc = j+col[x];
                        if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 2) {
                            ans = max(ans,1+find(newr,newc,x,0,grid,n,m));
                        }
                    }
                }
            }
        }
        return ans;
    }
};