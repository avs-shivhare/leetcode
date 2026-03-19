class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> prefix(n,vector<int>(m,0)), count(n,vector<int>(m,0));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 'X') {
                    prefix[i][j]++;
                    count[i][j]++;
                }
                else if(grid[i][j] == 'Y') {
                    prefix[i][j]--;
                }
                if(i>0) {
                    prefix[i][j] += prefix[i-1][j];
                    count[i][j] += count[i-1][j];
                }
                if(j>0) {
                    prefix[i][j] += prefix[i][j-1];
                    count[i][j] += count[i][j-1];
                }
                if(i>0 && j>0) {
                    prefix[i][j] -= prefix[i-1][j-1];
                    count[i][j] -= count[i-1][j-1];
                }
                if(prefix[i][j] == 0 && count[i][j]) ans++;
            }
        }
        return ans;
    }
};