class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st,st2;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                st.insert(nums[i]^nums[j]);
            }
        }
        for(int i = 0; i<n; i++) {
            for(auto &j: st) st2.insert(nums[i]^j);
        }
        return st2.size();
    }
};