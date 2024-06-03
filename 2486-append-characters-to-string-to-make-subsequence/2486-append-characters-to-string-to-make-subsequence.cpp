class Solution {
public:
    int f(int ind,int i,string &s,string &t,vector<int> &dp) {
        if(i == t.size()) return 0;
        if(ind == s.size()) {
            if(i == t.size()) return 0;
            return t.size()-i;
        }
        if(dp[ind] != -1) return dp[ind];
        int take = 1e9,notTake = 1e9;
        if(s[ind] == t[i]) {
            take = f(ind+1,i+1,s,t,dp);
        }
        notTake = f(ind+1,i,s,t,dp);
        return dp[ind] = min(take,notTake);
    }
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(n,-1);
        return f(0,0,s,t,dp);
    }
};