class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9+7;
    int find(int r,int c,int sum,vector<vector<int>> &grid,int &k) {
        if(r >= grid.size() || c >= grid[0].size()) return 0;
        if(r == grid.size()-1 && c == grid[0].size()-1) {
            if((sum+grid[r][c])%k == 0) return 1;
            return 0;
        }
        if(dp[r][c][sum] != -1) return dp[r][c][sum];
        int ans = find(r+1,c,(sum+grid[r][c])%k,grid,k)%mod;
        ans = (ans+find(r,c+1,(sum+grid[r][c])%k,grid,k))%mod;
        return dp[r][c][sum] = ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        dp.resize(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return find(0,0,0,grid,k);
    }
};