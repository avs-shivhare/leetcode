class Solution {
public:
    int mod = 1e9+7;
    int dp[501][501][2];
    int find(int r,int c,bool up,vector<vector<int>> &grid) {
        //cout<<r<<" "<<c<<" "<<up<<endl;
        if(r == grid.size()-1 && c == grid[0].size()-1) return 1;
        if(r >= grid.size() || c >= grid[0].size()) return 0;
        if(dp[r][c][up] != -1) return dp[r][c][up];
        if(grid[r][c]) {
            if(up) return dp[r][c][up] = find(r,c+1,false,grid)%mod;
            else return dp[r][c][up] = find(r+1,c,true,grid)%mod;
        }
        long long ans = find(r+1,c,true,grid)%mod;
        ans += find(r,c+1,false,grid)%mod;
        ans %= mod;
        return dp[r][c][up] = ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,false,grid);
    }
};