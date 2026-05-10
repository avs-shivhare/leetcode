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
    void create(string &s) {
        if(s.empty()) return;
        //cout<<s<<endl;
        Trie* temp = root;
        for(auto &i: s) {
            if(temp->next[i] == NULL) {
                temp->next[i] = new Trie();
            }
            temp = temp->next[i];
        }
        temp->cnt++;
        return;
    } 
    int search(string &s) {
        Trie* temp = root;
        for(auto &i: s) {
            if(temp->next[i] == NULL) return 0;
            temp = temp->next[i];
        }
        return temp->cnt;
    }
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(auto &i: chunks) {
            for(auto &j: i) {
                if('a' <= j && j <= 'z') {
                    s.push_back(j);
                } 
                else if(j == '-') {
                    if(!s.empty() && s.back() == '-') {
                        while(!s.empty() && s.back() == '-') s.pop_back();
                        create(s);
                        s = "";
                    }
                    else if(!s.empty()) s.push_back(j);
                    else {
                        while(!s.empty() && s.back() == '-') s.pop_back();
                        create(s);
                    }
                }
                else {
                    while(!s.empty() && s.back() == '-') s.pop_back();
                    create(s);
                    s = "";
                }
            }
        }
        while(!s.empty() && s.back() == '-') s.pop_back();
        create(s);
        vector<int> ans;
        for(auto &i: queries) {
            ans.push_back(search(i));
        }
        return ans;
    }
};