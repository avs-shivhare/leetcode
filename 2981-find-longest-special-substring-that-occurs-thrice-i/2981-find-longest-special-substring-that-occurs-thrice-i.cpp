class Trie {
    public:
    vector<Trie*> next;
    int cnt;
    Trie() {
        next.resize(26,NULL);
        cnt = 0;
    }
};

class Solution {
public:
    Trie* root = new Trie();
    void add(string &s,int ind) {
        Trie* temp = root;
        int i = ind;
        while(s[i] == s[ind] && i<s.size()) {
            if(temp->next[s[i]-'a']== NULL) {
                temp->next[s[i]-'a'] = new Trie();
            }
            temp = temp->next[s[i]-'a'];
            temp->cnt++;
            i++;
        }
    }
    int search(int ind) {
        Trie* temp = root;
        int cnt = 0;
        while(temp->next[ind]) {
            temp = temp->next[ind];
            if(temp->cnt < 3) {
                break;
            }
            cnt++;
        }
        return cnt;
    }
    int maximumLength(string s) {
        int n = s.size();
        for(int i = 0; i<n; i++) {
            add(s,i);
        }
        int ans = 0;
        for(int i = 0; i<26; i++) {
            ans = max(ans,search(i));
        }
        if(ans == 0) return -1;
        return ans;
    }
};