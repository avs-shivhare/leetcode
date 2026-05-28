class Trie {
    public:
    unordered_map<int,Trie*> next;
    int index;
    Trie() {
        index = 1e9;
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &s,int &ind,vector<string> &word,int maxi) {
        int n = s.size();
        Trie* temp = root;
        for(int i = n-1; i>=0 && n-i <= maxi; i--) {
            //cout<<s<<" "<<i<<endl;
            if(temp->next[s[i]-'a'] == NULL) {
                temp->next[s[i]-'a'] = new Trie();
            }
            temp = temp->next[s[i]-'a'];
            if(temp->index == 1e9) temp->index = ind;
            else if(n < word[temp->index].size()) temp->index = ind;
            else if(n == word[temp->index].size()) temp->index = min(temp->index,ind);
        }
        return;
    }
    int search(string &s) {
        Trie* temp = root;
        int n = s.size();
        for(int i = n-1; i>=0; i--) {
            if(temp->next[s[i]-'a'] == NULL) return temp->index;
            temp = temp->next[s[i]-'a'];
        }
        return temp->index;
    }
    vector<int> stringIndices(vector<string>& w, vector<string>& q) {
        root->index = 0;
        int n = w.size();
        int maxi = 0;
        for(auto &i: q) {
            maxi = max(maxi,(int)i.size());
        }
        for(int i = 0; i<n; i++) {
            add(w[i],i,w,maxi);
            if(w[root->index].size() > w[i].size()) root->index = i;
        }
        vector<int> ans;
        for(auto &i: q) {
            ans.push_back(search(i));
        }
        return ans;
    }
};