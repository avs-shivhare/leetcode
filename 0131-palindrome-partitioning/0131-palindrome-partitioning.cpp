class Solution {
public:
    void findPalindrome(int ind, string &s,int &n,vector<vector<string>> &ans,vector<string> &temp) {
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        for(int i =ind;i<n; i++) {
            if(isPalindrome(s,ind,i)) {
                temp.push_back(s.substr(ind,i-ind+1));
                findPalindrome(i+1,s,n,ans,temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string &s,int start,int end) {
        while(start < end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        findPalindrome(0,s,n,ans,temp);
        return ans;
    }
};