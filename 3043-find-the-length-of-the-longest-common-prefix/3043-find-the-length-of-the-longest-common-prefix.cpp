class Trie {
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(10,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void create(string &s) {
        Trie* temp = root;
        for(auto &i: s) {
            if(temp->next[i-'0'] == NULL) {
                temp->next[i-'0'] = new Trie();
            }
            temp = temp->next[i-'0'];
        }
        return;
    }
    int find(string &s) {
        Trie* temp = root;
        int cnt = 0;
        for(auto &i: s) {
            if(temp->next[i-'0'] == NULL) {
                return cnt;
            }
            temp = temp->next[i-'0'];
            cnt++;
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto &i: arr1) {
            string s = to_string(i);
            create(s);
        }
        int ans = 0;
        for(auto &i: arr2) {
            string s = to_string(i);
            ans = max(ans,find(s));
        }
        return ans;
    }
};