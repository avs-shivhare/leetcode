class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> pre(n,-1);
        pre[0] = 0;
        int cnt = 0;
        for(int i = 1; i<n; i++) {
            if(nums[i]%2 == nums[i-1]%2) cnt++;
            pre[i] = cnt;
        }
        vector<bool> ans;
        for(auto i: queries) {
            if(pre[i[0]] == pre[i[1]]) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};