class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> prefix(n+1,vector<int>(m+1,0));
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j<=m; j++) {
                if(matrix[i-1][j-1]) {
                    prefix[i][j] = min({prefix[i-1][j],prefix[i][j-1],prefix[i-1][j-1]})+1;
                }
                ans += prefix[i][j];
            }
        }
        // for(auto i: prefix) {
        //     for(auto j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};