class Solution {
public:
    void f(int ind,string &s,int &n,vector<vector<string>> &ans,vector<string> &temp) {
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i<n; i++) {
            if(isPalindrome(s,ind,i)) {
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,n,ans,temp);
                temp.pop_back();
            }
        }
        return;
    }
    bool isPalindrome(string &s,int start,int end) {
        while(start<=end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> temp;
        f(0,s,n,ans,temp);
        return ans;
    }
};