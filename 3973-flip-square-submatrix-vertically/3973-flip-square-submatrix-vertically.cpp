class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid.size();
        for(int i = y; i<y+k; i++) {
            int l = x;
            int r = x+k-1;
            while(l<=r) {
                swap(grid[l][i],grid[r][i]);
                l++;
                r--;
            }
        }
        return grid;
    }
};