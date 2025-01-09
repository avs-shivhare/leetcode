class Trie{
    public:
    vector<Trie*> next;
    int cnt = 0;
    Trie() {
        next.resize(26,NULL);
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
            temp->cnt++;
        }
        return;
    }
    int search(string &word) {
        int ans = 1e9;
        Trie* temp = root;
        for(auto i: word) {
            if(temp->next[i-'a'] == NULL) {
                return 0;
            }
            temp = temp->next[i-'a'];
            ans = min(ans,temp->cnt);
        }
        return ans;
    }
    int prefixCount(vector<string>& words, string pref) {
        for(auto i: words) {
            add(i);
        }
        return search(pref);
    }
};