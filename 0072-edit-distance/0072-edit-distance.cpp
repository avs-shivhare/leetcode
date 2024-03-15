class Solution {
public:
    //recursion solution with dp on 0 based indexing 
    // int f(int i,int j,vector<vector<int>> &dp,string &w1,string &w2) {
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(w1[i] == w2[j]) return dp[i][j] = f(i-1,j-1,dp,w1,w2);
    //     int in = 1+f(i,j-1,dp,w1,w2);
    //     int del = 1+f(i-1,j,dp,w1,w2);
    //     int rep = 1+f(i-1,j-1,dp,w1,w2);
    //     return dp[i][j] = min(in,min(del,rep));
    // }

    // recursion with dp using 1 based indexing
    // int f(int i,int j,vector<vector<int>> &dp,string &w1,string &w2) {
    //     if(i == 0) return j;
    //     if(j == 0) return i;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(w1[i-1] == w2[j-1]) return dp[i][j] = f(i-1,j-1,dp,w1,w2);
    //     int in = 1+f(i,j-1,dp,w1,w2);
    //     int del = 1+f(i-1,j,dp,w1,w2);
    //     int rep = 1+f(i-1,j-1,dp,w1,w2);
    //     return dp[i][j] = min(in,min(del,rep));
    // }
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,dp,word1,word2);
    // }

    //tabulation with 1 based indexing 
    //Used 2D array
    // int minDistance(string word1, string word2) {
    //     int n = word1.size();
    //     int m = word2.size();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int i =0; i<=n ; i++) dp[i][0] = i;
    //     for(int j =1; j<=m; j++) dp[0][j] = j;
    //     for(int i =1; i<=n; i++) {
    //         for(int j =1; j<=m; j++) {
    //             if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
    //             else dp[i][j] = 1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
    //         }
    //     }
    //     return dp[n][m];
    // }

    //space optimization with dp
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m+1,0), curr(m+1,0);
        // for(int i =0; i<=n ; i++) dp[i][0] = i;
        for(int j =0; j<=m; j++) {
            dp[j] = j;
        }
        for(int i =1; i<=n; i++) {
            curr[0] = i;
            for(int j =1; j<=m; j++) {
                if(word1[i-1] == word2[j-1]) curr[j] = dp[j-1];
                else curr[j] = 1+min(curr[j-1],min(dp[j],dp[j-1]));
            }
            dp = curr;
        }
        return dp[m];
    }
};