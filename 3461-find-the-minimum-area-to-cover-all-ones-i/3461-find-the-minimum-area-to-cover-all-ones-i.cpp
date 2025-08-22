class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int r1 = 1e9,r2 = 0;
        int c1 = 1e9,c2 = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]) {
                    r1 = min(r1,i);
                    r2 = max(r2,i);
                    c1 = min(c1,j);
                    c2 = max(c2,j);
                }
            }
        }
        //cout<<r1<<" "<<r2<<" "<<c1<<" "<<c2<<endl;
        return (r2-r1+1)*(c2-c1+1);
    }
};