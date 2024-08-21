class Solution {
public:
    int dp[101][101];
    int find(int i,int j,string &s) {
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
        for(int x = i; x<j; x++) {
            ans = min(ans,find(i,x,s)+find(x+1,j,s));
        }
        if(s[i] == s[j]) return dp[i][j] = ans-1;
        return dp[i][j] = ans;
    }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return find(0,s.size()-1,s);
    }
};