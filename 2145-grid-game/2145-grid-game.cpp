class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> prefix1(m+1,0),prefix2(m+1,0);
        for(int i = 1; i<=m; i++) {
            prefix1[i] = prefix1[i-1]+grid[0][i-1];
            prefix2[i] = prefix2[i-1]+grid[1][i-1];
        }
        long long ans = 1e18;
        for(int i = 0; i<m; i++) {
            ans = min(ans,max(prefix1[m]-prefix1[i+1],prefix2[i]));
        }
        return ans;
    }
};