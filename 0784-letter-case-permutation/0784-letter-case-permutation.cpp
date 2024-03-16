class Solution {
public:
    void f(int i,string s,unordered_set<string> &ans) {
        if(i <0) return;
        s[i] = tolower(s[i]);
        ans.insert(s);
        f(i-1,s,ans);
        s[i] = toupper(s[i]);
        ans.insert(s);
        f(i-1,s,ans);
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        unordered_set<string> ans;
        f(n-1,s,ans);
        vector<string> ans1;
        for(string i:ans) {
            ans1.push_back(i);
        }
        return ans1;
    }
};