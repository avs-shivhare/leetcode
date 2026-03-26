class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<long long,int> mpp,mppp;
        unordered_map<long long,int> mpp2;
        long long sum = 0;
        for(auto &i: grid) {
            for(auto &j: i) {
                mpp[j]++;
                mppp[j]++;
                sum += j;
            }
        }
        long long temp = sum;
        long long sum2 = 0;
        for(int i = 0; i<n-1; i++) {
            for(int j = 0; j<m; j++) {
                sum -= grid[i][j];
                sum2 += grid[i][j];
                mpp[grid[i][j]]--;
                mpp2[grid[i][j]]++;
            }
            if(sum == sum2) return true;
            else if(sum > sum2) {
                long long diff = sum-sum2;
                if(i<n-2 && mpp[diff] > 0 && m > 1) return true;
                else if(i <= n-2 && (grid[n-1][0] == diff || grid[n-1][m-1] == diff)) return true;
            }
            else {
                long long diff = sum2-sum;
                //cout<<diff<<" "<<grid[i][m-1]<<endl;
                if(i >= 1 && mpp2[diff] > 0 && m > 1) return true;
                else if(i >= 0 && (grid[0][0] == diff || grid[0][m-1] == diff || diff == grid[i][0] || diff == grid[i][m-1])) return true;
                else if(m ==1) {
                    for(int j =0; j<m; j++) {
                        if(diff == grid[i][j]) return true;
                    }
                }
            }
        }
        sum = temp;
        sum2 = 0;
        mpp2.clear();
        for(int j = 0; j<m-1; j++) {
            for(int i = 0; i<n; i++) {
                sum -= grid[i][j];
                sum2 += grid[i][j];
                mppp[grid[i][j]]--;
                mpp2[grid[i][j]]++;
            }
            if(sum == sum2) return true;
            else if(sum > sum2) {
                long long diff = sum-sum2;
                if(j<m-2 && mppp[diff] > 0 && n > 1) return true;
                else if(j <= m-2 && (grid[0][m-1] == diff || grid[n-1][m-1] == diff)) return true;
            }
            else {
                long long diff = sum2-sum;
                if(j >= 1 && mpp2[diff] > 0 && n > 1) return true;
                else if(j >= 0 && (grid[0][0] == diff || grid[n-1][0] == diff || diff == grid[0][j] || diff == grid[n-1][j])) return true;
                else if(n == 1) {
                    for(int i = 0; i<n; i++) {
                        if(grid[i][j] == diff) return true;
                    }
                }
            }
        }
        return false;
    }
};