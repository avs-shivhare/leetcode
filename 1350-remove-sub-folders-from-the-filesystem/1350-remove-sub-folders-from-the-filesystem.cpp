class Trie{
    public:
    unordered_map<string,Trie*> next;
    bool flag;
    Trie() {
        flag = false;
    }
};

class Solution {
public:
    string ss = "";
    vector<string> ans;
    Trie* root = new Trie();
    void add(string x) {
        stringstream s(x);
        string t = "";
        Trie* temp = root;
        while(getline(s,t,'/')) {
            if(t.empty()) continue;
            if(temp->next.count(t) == 0) {
                temp->next[t] = new Trie();
            }
            temp = temp->next[t];
            if(temp->flag) break;
        }
        temp->flag = true;
        return;
    }

    void search(Trie* temp) {
        if(temp->flag) {
            ans.push_back(ss);
            return;
        }
        for(auto i: temp->next) {
            int len = ss.size();
            ss += "/"+i.first;
            search(i.second);
            ss.erase(len);
        }
        return;
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        for(auto i: folder) {
            add(i);
        }
        search(root);
        return ans;
    }
};