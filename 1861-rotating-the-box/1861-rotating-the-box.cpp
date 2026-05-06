class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i = 0; i<n; i++) {
            int y = n-i-1,x = m-1;
            for(int j = m-1; j>=0; j--) {
                if(mat[i][j] == '*') {
                    ans[j][y] = '*';
                    x = j-1;
                }
                else if(mat[i][j] == '#') {
                    ans[x][y] = '#';
                    x--;
                }
            }
        }
        return ans;
    }
};