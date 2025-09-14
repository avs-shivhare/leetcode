class Trie {
    public:
    vector<Trie*> next;
    bool end;
    Trie() {
        next.resize(256,NULL);
        end = false;
    }
};
class Solution {
public:
    Trie *root = new Trie();
    void add(string &s) {
        Trie* temp = root;
        for(auto i: s) {
            if(temp->next[i] == NULL) {
                temp->next[i] = new Trie();
            }
            temp = temp->next[i];
        }
        temp->end = true;
        return;
    }
    bool search(string &s) {
        Trie* temp = root;
        for(auto i: s) {
            if(temp->next[i] == NULL) return false;
            temp = temp->next[i];
        }
        return temp->end;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        //vector<string> adj[26];
        unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        for(auto &i: wordlist) {
            add(i);
            // if(st.find(i[0]) != st.end()) {
            //     for(int k = 0; k<26; k++) {
            //         adj[k].push_back(i);
            //     }
            //     continue;
            // }
            // char x = tolower(i[0]);
            // adj[x-'a'].push_back(i);
        }
        vector<string> ans;
        for(auto &i: queries) {
            if(search(i)) ans.push_back(i);
            else {
                bool flag = false;
                for(auto &x: wordlist) {
                    if(i.size() != x.size()) continue;
                    bool temp = true;
                    for(int p = 0; p<x.size(); p++) {
                        if(tolower(i[p]) != tolower(x[p])) {
                            temp = false;
                            break;
                        }
                    }
                    if(temp) {
                        ans.push_back(x);
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                for(auto &x: wordlist) {
                    if(i.size() != x.size()) continue;
                    bool temp = true;
                    for(int p = 0; p<x.size(); p++) {
                        if(st.find(i[p]) != st.end() && st.find(x[p]) != st.end()) continue;
                        if(tolower(i[p]) != tolower(x[p])) {
                            temp = false;
                            break;
                        }
                    }
                    if(temp) {
                        ans.push_back(x);
                        flag = true;
                        break;
                    }
                }
                if(flag) continue;
                ans.push_back("");
            }
        }
        return ans;
    }
};