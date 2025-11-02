class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l = 1e9,r = 0;
        unordered_set<int> st;
        for(auto &i: nums) {
            st.insert(i);
            l = min(l,i);
            r = max(r,i);
        }
        vector<int> ans;
        for(int i = l; i<=r; i++) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};