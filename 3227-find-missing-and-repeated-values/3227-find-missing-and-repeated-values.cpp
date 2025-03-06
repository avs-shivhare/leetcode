class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> ans;
        for(int i = 0;i<n; i++) {
            for(int j = 0; j<n; j++) {
                int el = abs(grid[i][j])-1;
                int row = el/n;
                int col = el-(n*row);
                if(grid[row][col] < 0) {
                    ans.push_back(abs(grid[i][j]));
                }
                else grid[row][col] *= -1;
            }
        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] > 0) ans.push_back((i*n)+j+1);
            }
        }
        return ans;
    }
};