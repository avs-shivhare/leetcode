class Trie{
    public: 
    unordered_map<char,Trie*> mpp;
    bool isEnd;
    Trie() {
        isEnd = false;
    }
};
class Solution {
public:
    Trie* root = new Trie();
    bool add(string &word) {
        Trie* temp = root;
        int n = word.size();
        for(int j = 0; j<n; j++) {
            char i = word[j];
            if(temp->isEnd) {
                if(j+1 < n && word[j] == '/') return false;
            }
            if(temp->mpp.count(i) == 0) {
                temp->mpp[i] = new Trie();
            }
            temp = temp->mpp[i];
        }
        temp->isEnd = true;
        return true;
    }
    vector<string> removeSubfolders(vector<string>& fol) {
        sort(fol.begin(),fol.end());
        vector<string> ans;
        for(auto i: fol) {
            if(add(i)) ans.push_back(i);
        }
        return ans;
    }
};