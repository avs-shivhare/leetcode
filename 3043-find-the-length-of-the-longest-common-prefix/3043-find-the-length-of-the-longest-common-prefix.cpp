class Trie{
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(10,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &word) {
        Trie* temp = root;
        for(auto i: word) {
            if(temp->next[i-'0'] == NULL) {
                temp->next[i-'0'] = new Trie();
            }
            temp = temp->next[i-'0'];
        }
    }
    int search(string &word) {
        int cnt =0;
        Trie* temp = root;
        for(auto i: word) {
            if(temp->next[i-'0'] == NULL) return cnt;
            temp = temp->next[i-'0'];
            cnt++;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto i: arr1) {
            string temp = to_string(i);
            add(temp);
        }
        int ans = 0;
        for(auto i: arr2) {
            string temp = to_string(i);
            ans = max(ans,search(temp));
        }
        return ans;
    }
};