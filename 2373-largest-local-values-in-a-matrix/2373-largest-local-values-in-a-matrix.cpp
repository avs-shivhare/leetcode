class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2,vector<int>(n-2,0));
        for(int i = 1; i<n-1; i++) {
            for(int j =1; j<n-1; j++) {
                int maxi = 0;
                for(int k = i-1; k<=i+1; k++) {
                    for(int x = j-1; x<= j+1; x++) {
                        maxi = max(maxi,grid[k][x]);
                    }
                }
                ans[i-1][j-1] = maxi;
            }
        }
        return ans;
    }
};