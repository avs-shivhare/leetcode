class Solution {
public:
    // int dp[201][201][101];
    // int find(int r,int c,int k,vector<vector<int>> &grid,int &n,int &m) {
    //     //cout<<r<<" "<<c<<" "<<k<<endl;
    //     if(r >= n || c >= m || k < 0) return -1e9;
    //     if(r == n-1 && c == m-1) {
    //         if(k-(grid[r][c] >= 1 ? 1: 0) >= 0) return grid[r][c];
    //         return -1e9;
    //     }
    //     if(dp[r][c][k] != -1) return dp[r][c][k];
    //     int ans = grid[r][c]+find(r+1,c,k-(grid[r][c] >= 1 ? 1: 0),grid,n,m);
    //     ans = max(ans,grid[r][c]+find(r,c+1,k-(grid[r][c] >= 1 ? 1: 0),grid,n,m));
    //     return dp[r][c][k] = ans;
    // }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(k+1,-1e9));
        for(int r = n-1; r>=0; r--) {
            vector<vector<int>> temp(m,vector<int>(k+1,-1e9));
            for(int c = m-1; c>=0; c--)  {
                for(int x = k; x>=0; x--) {
                    if(r == n-1 && c == m-1) {
                        if(x-(grid[r][c] >= 1 ? 1: 0) >= 0) temp[c][x] = grid[r][c];
                        else temp[c][x] = -1e9;
                        continue;
                    }
                    if(x-(grid[r][c] >= 1 ? 1: 0) < 0) continue;
                    int ans = -1e9;
                    if(r+1 < n) ans = grid[r][c]+dp[c][x-(grid[r][c] >= 1 ? 1: 0)];
                    if(c+1 < m) ans = max(ans,grid[r][c]+temp[c+1][x-(grid[r][c] >= 1 ? 1: 0)]);
                    temp[c][x] = ans;
                }
            }
            dp = temp;
            // for(int i = 0; i<k; i++) {
            //     cout<<dp[i]<<" ";
            // }
            // cout<<endl;
        }
        if(dp[0][k] < 0) return -1;
        return dp[0][k];
    }
};