class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        long long sum = 0;
        for(auto &i: grid) {
            for(auto &j: i) {
                sum += j;
            }
        }
        long long sum2 = 0,sum3 = sum;
        for(int i = 0; i<n-1; i++) {
            for(auto &j: grid[i]) {
                sum2 += j;
                sum -= j;
            }
            if(sum2 == sum) return true;
        }
        sum = 0;
        for(int j = 0; j<m-1; j++) {
            for(int i = 0; i<n; i++) {
                sum += grid[i][j];
                sum3 -= grid[i][j];
            }
            if(sum == sum3) return true;
        }
        return false;
    }
};