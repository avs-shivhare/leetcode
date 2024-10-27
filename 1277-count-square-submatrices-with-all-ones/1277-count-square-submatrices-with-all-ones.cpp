class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for(int i = 0; i<n; i++) {
            dp[i][0] = matrix[i][0];
            sum += dp[i][0];
        }
        for(int i = 0; i<m; i++) {
            dp[0][i] = matrix[0][i];
            if(i>0) sum += dp[0][i];
        }
        for(int i =1; i<n; i++) {
            for(int j =1; j<m; j++) {
                if(matrix[i][j]) {
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};