class Solution {
public:
    //recursion with dp using 0 based indexing
    // bool f(int i,int j,vector<vector<int>> &dp,string &s,string &p) {
    //     if(i<0 && j<0) return true;
    //     if(i>=0 && j<0) return false;
    //     if(i<0 && j>=0) {
    //         for(int ii =0; ii <=j; ii++) {
    //             if(p[ii] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == p[j] || p[j] == '?') return dp[i][j] =f(i-1,j-1,dp,s,p);
    //     if(p[j] == '*') {
    //         return dp[i][j] = f(i-1,j,dp,s,p) || f(i,j-1,dp,s,p);
    //     }
    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,dp,s,p);
    // }

    //recursive solution with dp using 0 based indexing
    // bool f(int i,int j,vector<vector<int>> &dp,string &s,string &p) {
    //     if(i==0 && j==0) return true;
    //     if(i>0 && j==0) return false;
    //     if(i==0 && j>0) {
    //         for(int ii =1; ii <=j; ii++) {
    //             if(p[ii-1] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] =f(i-1,j-1,dp,s,p);
    //     if(p[j-1] == '*') {
    //         return dp[i][j] = f(i-1,j,dp,s,p) || f(i,j-1,dp,s,p);
    //     }
    //     return false;
    // }
    // bool isMatch(string s, string p) {
    //     int n = s.size();
    //     int m = p.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,dp,s,p);
    // }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,-false));
        dp[0][0] = true;
        for(int i =1; i<=n; i++) dp[i][0] = false;
        for(int j =1; j<=m; j++) {
            bool flag = true;
            for(int ii =1; ii <=j; ii++) {
                if(p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i =1; i<=n; i++) {
            for(int j =1; j<=m; j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] =dp[i-1][j-1];
                else if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j]= false;
            }
        }
        return dp[n][m];
    }

    
};