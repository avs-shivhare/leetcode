class Solution {
public:
    bool dp[301][301];
    bool check(int r,int c,int nr,int nc,vector<vector<int>> &grid,int &n,int &m) {
        if(nr < 0 || nr >= n || nc < 0 || nc >= m || dp[nr][nc]) return false;
        if(grid[r][c] == 1) {
            if(nr == r && nc == c+1 && (grid[nr][nc] == 1 || grid[nr][nc] == 3 || grid[nr][nc] == 5)) return true;
            if(nr == r && nc == c-1 && (grid[nr][nc] == 1 || grid[nr][nc] == 4 || grid[nr][nc] == 6)) return true;
        }
        else if(grid[r][c] == 2) {
            if(nr == r+1 && nc == c && (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) return true;
            if(nr == r-1 && nc == c && (grid[nr][nc] == 3 || grid[nr][nc] == 4 || grid[nr][nc] == 2)) return true;
        }
        else if(grid[r][c] == 3) {
            if(nr == r && nc == c-1 && (grid[nr][nc] == 1 || grid[nr][nc] == 6 || grid[nr][nc] == 4)) return true;
            if(nr == r+1 && nc == c && (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) return true;
        }
        else if(grid[r][c] == 4) {
            if(nr == r && nc == c+1 && (grid[nr][nc] == 1 || grid[nr][nc] == 5 || grid[nr][nc] == 3)) return true;
            if(nr == r+1 && nc == c && (grid[nr][nc] == 2 || grid[nr][nc] == 5 || grid[nr][nc] == 6)) return true;
        }
        else if(grid[r][c] == 5) {
            if(nr == r && nc == c-1 && (grid[nr][nc] == 1 || grid[nr][nc] == 6 || grid[nr][nc] == 4)) return true;
            if(nr == r-1 && nc == c && (grid[nr][nc] == 2 || grid[nr][nc] == 3 || grid[nr][nc] == 4)) return true;
        }
        else {
            if(nr == r && nc == c+1 && (grid[nr][nc] == 1 || grid[nr][nc] == 5 || grid[nr][nc] == 3)) return true;
            if(nr == r-1 && nc == 0 && (grid[nr][nc] == 2 || grid[nr][nc] == 3 || grid[nr][nc] == 4)) return true;
        }
        return false;
    }
    bool find(int r,int c,vector<vector<int>> &grid,int &n,int &m) {
        //cout<<r<<" "<<c<<endl;
        if(r < 0 || r >= n || c < 0 || c >= m || dp[r][c]) return false;
        if(r == n-1 && c == m-1) return true;
        dp[r][c] = true;
        if(grid[r][c] == 1) return (check(r,c,r,c+1,grid,n,m) && find(r,c+1,grid,n,m)) || (check(r,c,r,c-1,grid,n,m) && find(r,c-1,grid,n,m));
        else if(grid[r][c] == 2) return (check(r,c,r+1,c,grid,n,m) && find(r+1,c,grid,n,m)) || (check(r,c,r-1,c,grid,n,m) && find(r-1,c,grid,n,m));
        else if(grid[r][c] == 3) return (check(r,c,r,c-1,grid,n,m) && find(r,c-1,grid,n,m)) || (check(r,c,r+1,c,grid,n,m) && find(r+1,c,grid,n,m));
        else if(grid[r][c] == 4) return (check(r,c,r,c+1,grid,n,m) && find(r,c+1,grid,n,m)) || (check(r,c,r+1,c,grid,n,m) && find(r+1,c,grid,n,m));
        else if(grid[r][c] == 5) return (check(r,c,r-1,c,grid,n,m) && find(r-1,c,grid,n,m)) || (check(r,c,r,c-1,grid,n,m) && find(r,c-1,grid,n,m));
        else if(grid[r][c] == 6) return (check(r,c,r-1,c,grid,n,m) && find(r-1,c,grid,n,m)) || (check(r,c,r,c+1,grid,n,m) && find(r,c+1,grid,n,m));
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        memset(dp,false,sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        return find(0,0,grid,n,m);
    }
};