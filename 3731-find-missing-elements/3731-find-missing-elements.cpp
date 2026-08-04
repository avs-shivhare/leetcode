class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int maxi = -1e9,mini = 1e9;
        vector<int> ans;
        for(auto &i: nums) {
            maxi = max(maxi,i);
            mini = min(mini,i);
            st.insert(i);
        }
        for(int i = mini; i<=maxi; i++) {
            if(st.find(i) == st.end()) ans.push_back(i);
        }
        return ans;
    }
};