class Solution {
public:
    bool check(vector<vector<int>> &grid,int r,int c,int len) {
        vector<int> row(len,0),col(len,0);
        int sum = 0,sum2 = 0;
        for(int i = 0; i<len; i++) {
            for(int j = 0; j<len; j++) {
                row[i] += grid[r+i][c+j];
                col[j] += grid[r+i][c+j];
            }
            sum += grid[r+i][c+i];
            sum2 += grid[r+i][len-i-1+c];
        }
        if(sum == sum2) {
            for(auto &i: row) {
                if(sum != i) return false;
            }
            for(auto &i: col) {
                if(sum != i) return false;
            }
            return true;
        }
        // cout<<len<<" "<<r<<" "<<c<<endl;
        // for(auto i: row) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: col) cout<<i<<" ";
        // cout<<endl;
        // cout<<sum<<" "<<sum2<<endl;
        return false;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                for(int k = min(n-i,m-j); k>0 && k > ans; k--) {
                    if(check(grid,i,j,k) && ans < k) ans = k; 
                }
            }
        }
        return ans;
    }
};