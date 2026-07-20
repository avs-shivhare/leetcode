class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        k %= (n*m);
        if(k == 0) return grid;
        int rem = (n*m)-k;
        int r = rem/m,c = rem%m;
        r %= n;
        int i = 0;
        while(i<n) {
            int j = 0;
            while(j<m) {
                //cout<<i<<" "<<j<<" "<<r<<" "<<c<<endl;
                ans[i][j] = grid[r][c];
                c++;
                j++;
                r += c/m;
                c %= m;
                r %= n;
            }
            i++;
        }
        return ans;
    }
};