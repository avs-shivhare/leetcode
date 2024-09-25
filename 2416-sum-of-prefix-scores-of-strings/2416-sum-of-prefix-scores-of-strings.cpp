class Trie {
    public:
    int cnt;
    unordered_map<char,Trie*> next;
    Trie() {
        cnt = 0;
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &word) {
        Trie* temp = root;
        for(auto i: word) {
            if(temp->next.count(i) == 0) {
                temp->next[i] = new Trie();
            }
            temp = temp->next[i];
            temp->cnt++;
        }
    }
    int search(string &word) {
        int ans = 0;
        Trie* temp = root;
        for(auto i: word) {
            temp = temp->next[i];
            ans += temp->cnt;
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        for(auto i: words) {
            add(i);
        }
        vector<int> ans;
        for(auto i: words) {
            ans.push_back(search(i));
        }
        return ans;
    }
};