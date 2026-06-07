class Solution {
public:
    string s = "";
    vector<string> ans;
    void find(int i,int k,int &n) {
        if(k < 0) return;
        if(i == n) {
            ans.push_back(s);
            return;
        }
        if(s.empty() || s.back() != '1') {
            s.push_back('1');
            find(i+1,k-i,n);
            s.pop_back();
        }
        s.push_back('0');
        find(i+1,k,n);
        s.pop_back();
        return;
    }
    vector<string> generateValidStrings(int n, int k) {
        find(0,k,n);
        return ans;
    }
};