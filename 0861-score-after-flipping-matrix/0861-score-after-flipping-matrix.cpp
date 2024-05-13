class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i<n; i++) {
            if(grid[i][0] == 0) {
                for(int j = 0; j<m; j++) {
                    grid[i][j]  = !grid[i][j];
                }
            }
        }
        for(int j =0; j<m; j++) {
            int one = 0,zero =0;;
            for(int i =0; i<n; i++) {
                if(grid[i][j]) {
                    one++;
                }
                else {
                    zero++;
                }
            }
            if(zero > one) {
                for(int i =0; i<n; i++) {
                    grid[i][j] = !grid[i][j];
                }
            }
        }
        int ans = 0;
        for(int i =0; i<n; i++) {
            int x = 0;
            for(int j =m-1; j>=0; j--) {
                if(grid[i][j]) {
                    ans += pow(2,x);
                }
                x++;
            }
        }
        return ans;
    }
};