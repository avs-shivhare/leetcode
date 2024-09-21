class Solution {
public:
    static bool compare(int &t1,int &t2) {
        string s1 = to_string(t1);
        string s2 = to_string(t2);
        if(s1 > s2) return false;
        return true;
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i =1; i<=n; i++) {
            ans.push_back(i);
        }
        sort(ans.begin(),ans.end(),compare);
        return ans;
    }
};