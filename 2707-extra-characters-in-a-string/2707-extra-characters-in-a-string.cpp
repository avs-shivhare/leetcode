class Trie {
    public:
    vector<Trie*> next;
    bool end;
    Trie() {
        next.resize(26,NULL);
        end = false;
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &word) {
        Trie* temp = root;
        for(auto i: word) {
            if(temp->next[i-'a'] == NULL) {
                temp->next[i-'a'] = new Trie();
            }
            temp = temp->next[i-'a'];
        }
        temp->end = true;
    }
    int dp[51];
    int search(int i,string &s) {
        if(i == s.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = 1e9;
        Trie* temp = root;
        if(temp->next[s[i]-'a'] == NULL) return 1+search(i+1,s);
        for(int x = i; x<s.size(); x++) {
            if(temp->end) {
                ans = min(ans,search(x,s));
            }
            if(temp->next[s[x]-'a'] == NULL) {
                return dp[i] = ans = min(ans,search(x,s)+x-i);
                
            }
            else {
                temp = temp->next[s[x]-'a'];
            }
            if(i != x) {
                ans = min(ans,search(x,s)+x-i);
            }
            //cout<<x<<" "<<ans<<endl;
        }
        if(temp->end) return dp[i] = 0;
        return dp[i] = min((int)s.size()-i,ans);
    }
    int minExtraChar(string s, vector<string>& dict) {
        memset(dp,-1,sizeof(dp));
        for(auto i: dict) {
            add(i);
        }
        return search(0,s);
    }
};