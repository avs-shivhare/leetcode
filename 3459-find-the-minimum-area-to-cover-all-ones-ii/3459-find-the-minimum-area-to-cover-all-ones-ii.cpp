class Solution {
public:
    int find(vector<vector<int>> &grid,int s1,int s2,int sc1,int sc2) {
        int r1 = 1e9,r2 = 0;
        int c1 = 1e9,c2 = 0;
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        for(int i = s1; i<=s2; i++) {
            for(int j = sc1; j<=sc2; j++) {
                if(grid[i][j]) {
                    r1 = min(r1,i);
                    r2 = max(r2,i);
                    c1 = min(c1,j);
                    c2 = max(c2,j);
                    flag = true;
                }
            }
        }
        if(flag) return (r2-r1+1)*(c2-c1+1);
        return 0;
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
        for(int i = 0; i<n; i++) {
            int first = find(grid,0,i,0,m-1);
            for(int j = 0; j<m; j++) {
                int second = find(grid,i+1,n-1,0,j);
                int third = find(grid,i+1,n-1,j+1,m-1);
                ans = min(ans,first+second+third);
            }
        }
        for(int i = 0; i<n; i++) {
            int first = find(grid,i+1,n-1,0,m-1);
            for(int j = 0; j<m; j++) {
                int second = find(grid,0,i,0,j);
                int third = find(grid,0,i,j+1,m-1);
                ans = min(ans,first+second+third);
            }
        }
        for(int j = 0; j<m; j++) {
            int first = find(grid,0,n-1,0,j);
            for(int i = 0; i<n; i++) {
                int second = find(grid,0,i,j+1,m-1);
                int third = find(grid,i+1,n-1,j+1,m-1);
                ans = min(ans,first+second+third);
            }
        }
        for(int j = 0; j<m; j++) {
            int first = find(grid,0,n-1,j+1,m-1);
            for(int i = 0; i<n; i++) {
                int second = find(grid,0,i,0,j);
                int third = find(grid,i+1,n-1,0,j);
                ans = min(ans,first+second+third);
            }
        }
        for(int i = 0; i<n; i++) {
            int first = find(grid,0,i,0,m-1);
            for(int j = i+1; j<n; j++) {
                int second = find(grid,i+1,j,0,m-1);
                int third = find(grid,j+1,n-1,0,m-1);
                ans = min(ans,first+second+third);
            }
        }
        for(int i = 0; i<m; i++) {
            int first = find(grid,0,n-1,0,i);
            for(int j = i+1; j<m; j++) {
                int second = find(grid,0,n-1,i+1,j);
                int third = find(grid,0,n-1,j+1,m-1);
                ans = min(ans,first+second+third);
            }
        }
        return ans;
    }
};