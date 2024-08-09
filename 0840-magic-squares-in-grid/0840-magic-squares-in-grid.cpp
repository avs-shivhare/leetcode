class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        for(int i =0; i+2<n; i++) {
            for(int j =0; j+2<m; j++) {
                bool flag = true;
                int row = 0;
                unordered_map<int,int> mpp;
                for(int x =0; x<3; x++) {
                    int temp = 0;
                    for(int y =0; y<3; y++) {
                        temp += grid[i+x][j+y];
                        if(grid[i+x][j+y] < 1 || grid[i+x][j+y] > 9) flag = false;
                        if(mpp.count(grid[i+x][j+y])) flag = false;
                        mpp[grid[i+x][j+y]]++;
                    }
                    if(row != 0 && temp != row) flag = false;
                    row = temp;
                    temp = 0;
                    for(int y =0; y<3; y++) {
                        temp += grid[i+y][j+x];
                    }
                    if(row != temp) flag = false;
                }
                int dig1 = grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
                int dig2 = grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2];
                if(row != dig1 || row != dig2) flag = false;
                if(flag) cnt++;
                cout<<row<<endl;
            }
        }
        return cnt;
    }
};