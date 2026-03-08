class Trie {
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(2,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    string ans = "";
    void create(string &s) {
        Trie* temp = root;
        for(auto &i: s) {
            if(temp->next[i-'0'] == NULL) temp->next[i-'0'] = new Trie();
            temp = temp->next[i-'0'];
        }
        return;
    }
    bool find(Trie* temp,int &n) {
        if(temp == NULL) {
            return ans.size() <= n;
        }
        ans.push_back('0');
        if(find(temp->next[0],n)) return true;
        ans.pop_back();
        ans.push_back('1');
        if(find(temp->next[1],n)) return true;
        ans.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto &i: nums) {
            create(i);
        }
        int n = nums[0].size();
        find(root,n);
        while(ans.size() < n) ans.push_back('0');
        return ans;
    }
};