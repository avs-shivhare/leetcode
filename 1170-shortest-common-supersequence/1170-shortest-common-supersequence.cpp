class Solution {
public:
    int dp[1001][1001];
    int find(int i,int j,string &s1,string &s2) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) {
            return dp[i][j] = 1+find(i+1,j+1,s1,s2);
        }
        return dp[i][j] = 0+max(find(i+1,j,s1,s2),find(i,j+1,s1,s2));
    }
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp,-1,sizeof(dp));
        find(0,0,str1,str2);
        int i = 0,j = 0;
        int n = str1.size();
        int m = str2.size();
        string ans = "";
        while(i<n && j< m) {
            if(str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else if(dp[i+1][j] >= dp[i][j+1]) {
                ans += str1[i];
                i++;
            }
            else {
                ans += str2[j];
                j++;
            }
        }
        while(i<n) ans += str1[i++];
        while(j<m) ans +=str2[j++];
        return ans;
    }
};