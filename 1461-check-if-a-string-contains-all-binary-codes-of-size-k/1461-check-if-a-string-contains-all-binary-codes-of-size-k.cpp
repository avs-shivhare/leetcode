class Trie {
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(2,NULL);
    }
};
class Solution {
public:
    Trie *root = new Trie();
    void create(string &s,int i,int &k) {
        int n = s.size();
        Trie *temp = root;
        for(int j = i; j-i<k; j++) {
            int x = s[j]-'0';
            if(temp->next[x] == NULL) temp->next[x] = new Trie();
            temp = temp->next[x];
        }
        return;
    }
    bool search(int n,int &k) {
        Trie* temp = root;
        for(int i = k-1; i>=0; i--) {
            int x = 0;
            if(n&(1<<i)) x = 1;
            if(temp->next[x] == NULL) return false;
            temp = temp->next[x];
        }
        return true;
    }
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        for(int i = 0; i+k<=n; i++) {
            create(s,i,k);
        }
        n = 1<<k;
        for(int i = 0; i<=n; i++) {
            if(!search(i,k)) return false;
        }
        return true;
    }
};