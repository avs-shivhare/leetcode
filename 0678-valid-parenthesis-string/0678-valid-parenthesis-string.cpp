class Solution {
public:
    int dp[101][101];
    int find(int i,int cnt,string &s) {
        if(cnt < 0) return 0;
        if(i >= s.size()) {
            return cnt == 0;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int ans = 0;
        if(s[i] == '(') ans = max(ans,find(i+1,cnt+1,s));
        else if(s[i] == ')') ans = max(ans,find(i+1,cnt-1,s));
        else {
            ans = max(ans,find(i+1,cnt+1,s));
            ans = max(ans,find(i+1,cnt-1,s));
            ans = max(ans,find(i+1,cnt,s));
        }
        return dp[i][cnt] = ans;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return find(0,0,s);
    }
};