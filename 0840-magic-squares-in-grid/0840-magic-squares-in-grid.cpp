class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i+3<=n; i++) {
            for(int j = 0; j+3<=m; j++) {
                unordered_map<int,int> mpp;
                bool flag = true;
                for(int x = 0; x<3; x++) {
                    for(int y = 0; y<3; y++) {
                        if(mpp[grid[i+x][j+y]] || grid[i+x][j+y] < 1 || grid[i+x][j+y] > 9) {
                            flag = false;
                            break;
                        }
                        mpp[grid[i+x][j+y]]++;
                    }
                    if(!flag) break;
                }
                if(!flag) continue;
                int r1 = grid[i][j]+grid[i][j+1]+grid[i][j+2];
                int r2 = grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
                int r3 = grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                int c1 = grid[i][j]+grid[i+1][j]+grid[i+2][j];
                int c2 = grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
                int c3 = grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
                int d1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int d2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
                if(r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == d1 && d1 == d2) cnt++;
            }
        }
        return cnt;
    }
};