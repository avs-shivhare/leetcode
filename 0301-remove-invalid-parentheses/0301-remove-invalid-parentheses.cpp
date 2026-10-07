class Solution {
public:
    set<string> st;
    string temp = "";
    int dp[26][26];
    int find(int i,int cnt,string &s) {
        if(cnt < 0) return 1e9;
        if(i >= s.size()) {
            if(cnt == 0) return 0;
            return 1e9;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int take = 1e9,notTake = 1e9;
        if(s[i] == '(') take = find(i+1,cnt+1,s);
        else if(s[i] == ')') take = find(i+1,cnt-1,s);
        else take = find(i+1,cnt,s);
        notTake = 1+find(i+1,cnt,s);
        return dp[i][cnt] = min(take,notTake);
    }
    void build(int i,int cnt,int cnt2,string &s) {
        if(cnt < 0 || cnt2 < 0) return;
        if(i >= s.size()) {
            if(cnt == 0 && cnt2 == 0) st.insert(temp);
            return;
        }
        temp.push_back(s[i]);
        if(s[i] == '(') build(i+1,cnt,cnt2+1,s);
        else if(s[i] == ')') build(i+1,cnt,cnt2-1,s);
        else build(i+1,cnt,cnt2,s);
        temp.pop_back();
        build(i+1,cnt-1,cnt2,s);
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        memset(dp,-1,sizeof(dp));
        int ans = find(0,0,s);
        build(0,ans,0,s);
        vector<string> res;
        for(auto &i: st) res.push_back(i);
        return res;
    }
};