class Solution {
public:
    int mod = 1e9+7;
    int dp[1001][1001];
    int find(int i,int j,vector<string> &word,string target,int &n,int &m) {
        if(j == target.size()) return 1;
        if(i == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int x = 0; x<n; x++) {
            if(target[j] == word[x][i]) ans = (ans+find(i+1,j+1,word,target,n,m))%mod;
        }
        ans = (ans+find(i+1,j,word,target,n,m))%mod;
        return dp[i][j] = ans;
    }
    int numWays(vector<string>& words, string target) {
        memset(dp,0,sizeof(dp));
        int n = words.size();
        int m = words[0].size();
        for(int i = 0; i<=m; i++) {
            dp[i][target.size()] =1;
        }
        vector<unordered_map<char,int>> temp;
        for(int j = 0; j<m; j++) {
            unordered_map<char,int> mpp;
            for(int i = 0; i<n; i++) {
                mpp[words[i][j]]++;
            }
            temp.push_back(mpp);
        }
        for(int j = target.size()-1; j>=0; j--) {
            for(int i = m-1; i>= 0; i--) {
                long long ans = 0;
                if(temp[i].count(target[j]) == 1) {
                    long long t = dp[i+1][j+1];
                    ans = (ans+(t*temp[i][target[j]]))%mod;
                }
                ans = (ans+dp[i+1][j])%mod;
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};