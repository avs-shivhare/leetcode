class Trie {
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
    void add(string &word,int start) {
        Trie* temp = root;
        int n = word.size();
        while(start<n) {
            if(temp->next[word[start]-'a'] == NULL) {
                temp->next[word[start]-'a'] = new Trie();
            }
            temp = temp->next[word[start]-'a'];
            temp->cnt++;
            start++;
        }
        return;
    }
    bool search(string &word) {
        int n = word.size();
        Trie* temp = root;
        int ans = 1e9;
        for(int i = 0; i<n; i++) {
            temp = temp->next[word[i]-'a'];
            ans = min(ans,temp->cnt);
        }
        return ans > 1;
    }
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(auto i: words) {
            int n = i.size();
            for(int j = 0; j<n; j++) {
                add(i,j);
            }
        }
        for(auto i: words) {
            if(search(i)) ans.push_back(i);
        }
        return ans;
    }
};