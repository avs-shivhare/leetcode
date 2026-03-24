class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> prefixRow(n,0),suffixRow(n,0);
        long long pro = 1;
        long long pro2 = 1;
        int mod = 12345;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                pro *= 1ll*grid[i][j];
                pro %= mod;
                pro2 *= 1ll*grid[n-i-1][j];
                pro2 %= mod;
            }
            prefixRow[i] = pro;
            suffixRow[n-i-1] = pro2;
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i = 0; i<n; i++) {
            vector<long long> prefix(m,0), suffix(m,0);
            pro = 1;
            pro2 = 1;
            for(int j = 0; j<m; j++) {
                pro *= 1ll*grid[i][j];
                pro %= mod;
                pro2 *= 1ll*grid[i][m-j-1];
                pro2 %= mod;
                prefix[j] = pro;
                suffix[m-j-1] = pro2;
            }
            for(int j = 0; j<m; j++) {
                long long u = (i>0 ? prefixRow[i-1]:1ll);
                long long b = (i<n-1? suffixRow[i+1]:1ll);
                long long l = (j>0?prefix[j-1]:1ll);
                long long r = (j<m-1?suffix[j+1]:1ll);
                ans[i][j] = ((l*r)%mod)*((u*b)%mod)%mod;
            }
        }
        return ans;
    }
};