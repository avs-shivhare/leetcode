class Solution {
public:
    int dp[101][101][101];
    int mod = 1e9+7;
    int find(int i,int j,int k,string &w1,string &w2,string &target) {
        if(k >= target.size()) {
            if(i == 0 || j == 0) return 0;
            return 1;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int ans = 0;
        for(int x = i; x<w1.size(); x++) {
            if(w1[x] == target[k]) ans = (ans+find(x+1,j,k+1,w1,w2,target))%mod;
        }
        for(int x = j; x<w2.size(); x++) {
            if(w2[x] == target[k]) ans = (ans+find(i,x+1,k+1,w1,w2,target))%mod;
        }
        return dp[i][j][k] = ans;
    }
    int interleaveCharacters(string word1, string word2, string target) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,0,word1,word2,target);
    }
};