class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(),nums.end());
        long long x = k;
        while(st.find(x) != st.end()) {
            x += k;
        }
        return x;
    }
};