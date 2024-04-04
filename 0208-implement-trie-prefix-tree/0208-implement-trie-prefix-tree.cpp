class Node{
    public:
    Node* links[26];
    bool flag = false;
    bool isContain(char i) {
        return links[i-'a'] != NULL;
    }
    Node* get(char i) {
        return links[i-'a'];
    }
    void put(char i,Node* data) {
        links[i-'a'] = data;
    }
    void setEnd() {
        flag = true;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
       int n = word.size();
       Node* data = root;
       for(int i =0; i<n; i++) {
        if(!data->isContain(word[i])) {
            data->put(word[i],new Node());
        }
        data = data->get(word[i]);
       } 
       data->setEnd();
    }
    
    bool search(string word) {
        int n = word.size();
        Node* data = root;
        for(int i =0; i<n; i++) {
            if(!data->isContain(word[i])) {
                return false;
            }
            data = data->get(word[i]);
        }
        return data->flag;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        Node* data = root;
        for(int i =0;i<n; i++) {
            if(!data->isContain(prefix[i])) {
                return false;
            }
            data = data->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */