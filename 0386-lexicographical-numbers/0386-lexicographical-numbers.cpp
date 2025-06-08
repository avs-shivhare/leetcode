class Trie{
    public:
    vector<Trie*> next;
    bool last;
    Trie() {
        next.resize(10,NULL);
        last = false;
    }
};
class Solution {
public:
    vector<int> ans;
    Trie* root = new Trie();
    void add(string x) {
        Trie* temp = root;
        for(auto i: x) {
            if(temp->next[i-'0'] == NULL) {
                temp->next[i-'0'] = new Trie();
            }
            temp = temp->next[i-'0'];
        }
        temp->last = true;
        return;
    }
    void search(Trie* root,string &x) {
        if(root->last) {
            ans.push_back(stoi(x));
        }
        for(int i = 0; i<10; i++) {
            if(root->next[i]) {
                x.push_back(i+'0');
                search(root->next[i],x);
                x.pop_back();
            }
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1; i<=n; i++) {
            add(to_string(i));
        }
        string x = "";
        search(root,x);
        return ans;
    }
};