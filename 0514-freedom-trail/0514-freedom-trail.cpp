class Solution {
public:
    int f(int i,int j,string &ring,string &key,int &n,int &m,vector<vector<int>> &dp) {
        if(j == m) return 0;
        if(i>=n) return 1e9;
        int ans = 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        for(int ind = 0; ind<n; ind++) {
            if(ring[ind] == key[j]) {
                ans = min(ans,min(abs(ind-i),n-abs(ind-i))+1+f(ind,j+1,ring,key,n,m,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(0,0,ring,key,n,m,dp);
    }
};