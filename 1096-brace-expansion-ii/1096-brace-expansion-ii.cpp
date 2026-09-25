class Solution {
public:
    set<string> ans;
    void dfs(string s) {
        int r = s.find("}");
        if(r == string::npos) {
            ans.insert(s);
            return;
        }
        int l = s.rfind("{",r);
        string left = s.substr(0,l);
        string right = s.substr(r+1);
        string rem = s.substr(l+1,r-l-1);
        stringstream ss(rem);
        string temp;
        while(getline(ss,temp,',')) {
            dfs(left+temp+right);
        }
        return;
    }
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        vector<string> res;
        for(auto &i: ans) res.push_back(i);
        return res;
    }
};