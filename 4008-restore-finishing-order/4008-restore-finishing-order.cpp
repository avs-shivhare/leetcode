class Solution {
public:
    vector<int> recoverOrder(vector<int>& o, vector<int>& f) {
        unordered_set<int> st(f.begin(),f.end());
        vector<int> ans;
        for(auto i: o) {
            if(st.find(i) != st.end()) ans.push_back(i);
        }
        return ans;
    }
};