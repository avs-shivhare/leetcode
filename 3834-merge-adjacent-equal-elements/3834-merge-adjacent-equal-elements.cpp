class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> ans;
        int n = nums.size();
        for(int i = 0; i<n; i++) {
            long long el = nums[i];
            while(!ans.empty() && ans.back() == el) {
                el += ans.back();
                ans.pop_back();
            }
            ans.push_back(el);
        }
        return ans;
    }
};