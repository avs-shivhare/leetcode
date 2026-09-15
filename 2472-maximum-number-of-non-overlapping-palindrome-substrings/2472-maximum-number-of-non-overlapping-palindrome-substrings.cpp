class Solution {
public:
    int dp[2001];
    bool check(int l,int r,string &s) {
        while(l<=r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int find(int i,string &s,int &k) {
        if(i >= s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j = i+k-1; j<s.size(); j++) {
            if(check(i,j,s)) {
                ans = max(ans,1+find(j+1,s,k));
                break;
            }
        }
        ans = max(ans,find(i+1,s,k));
        return dp[i] = ans;
    }
    int maxPalindromes(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,s,k);
    }
};