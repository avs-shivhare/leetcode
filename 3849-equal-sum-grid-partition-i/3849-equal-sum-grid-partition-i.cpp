class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for(auto i: grid) {
            for(auto j: i) {
                sum += j;
            }
        }
        long long sum2 = sum;
        int n = grid.size();
        int m = grid[0].size();
        long long temp = 0;
        for(int i = 0; i<n-1; i++) {
            for(int j = 0; j<m; j++) {
                temp += grid[i][j];
                sum -= grid[i][j];
            }
            if(temp == sum) return true;
        }
        temp = 0;
        sum = sum2;
        for(int j = 0; j<m-1; j++) {
            for(int i = 0; i<n; i++) {
                temp += grid[i][j];
                sum -= grid[i][j];
            }
            if(temp == sum) return true;
        }
        return false;
    }
};