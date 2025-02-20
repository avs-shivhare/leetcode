class Trie{
    public:
    vector<Trie*> next;
    Trie() {
        next.resize(2,NULL);
    }
};
class Solution {
public:
    Trie* root = new Trie();
    void add(string &s) {
        Trie* temp = root;
        for(auto i: s) {
            if(temp->next[i-'0']== NULL) {
                temp->next[i-'0'] = new Trie();
            }
            temp = temp->next[i-'0'];
        }
    }
    string ans = "";
    bool find(int i,int &n,Trie* temp) {
        if(i == n) return temp == NULL;
        if(temp == NULL) {
            ans.push_back('0');
            if(find(i+1,n,temp)) return true;
            ans.pop_back();
            ans.push_back('1');
            if(find(i+1,n,temp)) return true;
            ans.pop_back();
            return false;
        }
        ans.push_back('1');
        if(find(i+1,n,temp->next[1])) return true;
        ans.pop_back();
        ans.push_back('0');
        if(find(i+1,n,temp->next[0])) return true;
        ans.pop_back();
        return false;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        for(auto i: nums) {
            add(i);
        }
        int n = nums[0].size();
        find(0,n,root);
        return ans;
    }
};