class Solution {
public:
    //recursion method with dp in 0 based indexing
    // int f(int i,int j,vector<vector<int>> &dp,string &s,string &t) {
    //     if(j<0) return 1;
    //     if(i<0) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]) {
    //         return dp[i][j]=f(i-1,j-1,dp,s,t)+f(i-1,j,dp,s,t);
    //     }
    //     return dp[i][j] = f(i-1,j,dp,s,t);
    // }

    //recursing solution with dp in 1 based indexing
    // int f(int i,int j,vector<vector<int>> &dp,string &s,string &t) {
    //     if(j == 0) return 1;
    //     if(i == 0) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i-1] == t[j-1]) {
    //         return dp[i][j]=f(i-1,j-1,dp,s,t)+f(i-1,j,dp,s,t);
    //     }
    //     return dp[i][j] = f(i-1,j,dp,s,t);
    // }
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,dp,s,t);
    // }

    //tabulation method with 2D array
    // int numDistinct(string s, string t) {
    //     int n = s.size();
    //     int m = t.size();
    //     vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    //     for(int i =0; i<=n; i++) dp[i][0] = 1;
    //     for(int i =1; i<=n; i++) {
    //         for(int j =1; j<=m; j++) {
    //             if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
    //             else dp[i][j] = dp[i-1][j];
    //         }
    //     }
    //     return (int)dp[n][m];
    // }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double> dp(m+1,0),curr(m+1,0);
        dp[0] = 1;
        for(int i =1; i<=n; i++) {
            curr[0] = 1;
            for(int j =1; j<=m; j++) {
                if(s[i-1] == t[j-1]) curr[j] = dp[j-1]+dp[j];
                else curr[j] = dp[j];
            }
            dp = curr;
        }
        return (int)dp[m];
    }
};