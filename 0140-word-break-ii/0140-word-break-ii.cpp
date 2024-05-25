class Solution {
public:
    class Tries{
        public:
        char c;
        int symbol;
        vector<Tries*> l;
        Tries(char c) {
            this->c = c;
            symbol = 0;
            l.resize(26,NULL);
        }
    };
    Tries* root = new Tries('a');
    vector<string> ans;
    void add(string word) {
        Tries* temp = root;
        for(char i: word) {
            if(temp->l[i-'a'] == NULL) {
                temp->l[i-'a'] = new Tries(i);
            }
            temp = temp->l[i-'a'];
        }
        temp->symbol++;
    }
    bool search(string word) {
        Tries* temp = root;
        for(char i: word) {
            if(temp->l[i-'a'] == NULL) return false;
            temp = temp->l[i-'a'];
        }
        if(temp->symbol >=1) return true;
        return false;
    }
    void solve(string &s,string temp,int ind) {
        if(ind == s.size()) {
            ans.push_back(temp);
            return;
        }
        temp += " ";
        for(int i = ind; i<s.size(); i++) {
            if(search(s.substr(ind,i+1-ind))) {
                solve(s,temp+s.substr(ind,i+1-ind),i+1);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string i: wordDict) add(i);
        int n = s.size();
        for(int i =0; i<n; i++) {
            if(search(s.substr(0,i+1))) {
                solve(s,s.substr(0,i+1),i+1);
            }
        }
        return ans;
    }
};