class Trie {
    public:
    vector<Trie*> next;
    int end = 0;
    Trie() {
        next.resize(26,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &s,int i) {
        int n = s.size();
        Trie* temp = root;
        for(; i<n; i++) {
            if(temp->next[s[i]-'a'] == NULL) {
                temp->next[s[i]-'a'] = new Trie();
            }
            temp = temp->next[s[i]-'a'];
            temp->end = 1;
        }
        temp->end = 1;
    } 
    int search(string &s) {
        int n = s.size();
        Trie* temp = root;
        for(int i = 0; i<n; i++) {
            if(temp->next[s[i]-'a'] == NULL) return 0;
            temp = temp->next[s[i]-'a'];
        }
        return temp->end;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        int n = word.size();
        for(int i = 0; i<n; i++) {
            add(word,i);
        }
        for(auto &i: patterns) {
            ans += search(i);
        }
        return ans;
    }
};